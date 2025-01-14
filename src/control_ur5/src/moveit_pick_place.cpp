#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <find_object_2d/DetectionInfo.h>
#include <geometry_msgs/PoseStamped.h>
#include <ros/ros.h>

class BoxTracker {
public:
    BoxTracker() {
        box_position_subscriber = nh.subscribe("/info", 10, &BoxTracker::boxPositionCallback, this);
    }

    void boxPositionCallback(const find_object_2d::DetectionInfo::ConstPtr& msg) {
        if (!msg->ids.empty()) {
            int index = 0; // Change this based on your logic to select the appropriate object
            if (msg->homographies.size() > index) {
                const auto& homography = msg->homographies[index].data;
                if (homography.size() == 9) {
                    current_box_position.x = homography[6]; // h31 = dx
                    current_box_position.y = homography[7]; // h32 = dy
                    current_box_position.z = 0.1; // Set a reasonable height for picking
                    current_box_orientation = {}; // Set appropriate orientation if needed
                    box_detected = true;
                } else {
                    ROS_WARN("Homography matrix size is incorrect.");
                    box_detected = false;
                }
            } else {
                ROS_WARN("No homography data available for the detected object.");
                box_detected = false;
            }
        } else {
            box_detected = false;
        }
    }

    bool isBoxDetected() const {
        return box_detected;
    }

    geometry_msgs::Point getBoxPosition() const {
        return current_box_position;
    }

    geometry_msgs::Quaternion getBoxOrientation() const {
        return current_box_orientation;
    }

private:
    ros::NodeHandle nh;
    ros::Subscriber box_position_subscriber;
    geometry_msgs::Point current_box_position;
    geometry_msgs::Quaternion current_box_orientation;
    bool box_detected = false;
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "pick_and_place_find_object");
    ros::NodeHandle n;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    BoxTracker box_tracker;

    static const std::string PLANNING_GROUP_ARM = "ur5_arm";
    static const std::string PLANNING_GROUP_GRIPPER = "gripper";

    moveit::planning_interface::MoveGroupInterface move_group_interface_arm(PLANNING_GROUP_ARM);
    moveit::planning_interface::MoveGroupInterface move_group_interface_gripper(PLANNING_GROUP_GRIPPER);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    // Move to home position
    move_group_interface_arm.setJointValueTarget(move_group_interface_arm.getNamedTargetValues("home"));
    move_group_interface_arm.move();

    // Continuous tracking loop
    while (ros::ok()) {
        if (box_tracker.isBoxDetected()) {
            geometry_msgs::Point box_position = box_tracker.getBoxPosition();
            ROS_INFO_STREAM("3D box position: x " << box_position.x 
                            << " y " << box_position.y 
                            << " z " << box_position.z);

            // Add the box to the planning scene
            moveit_msgs::CollisionObject collision_object;
            collision_object.header.frame_id = move_group_interface_arm.getPlanningFrame();
            collision_object.id = "detected_box";
            shape_msgs::SolidPrimitive primitive;
            primitive.type = primitive.BOX;
            primitive.dimensions = {0.1, 0.075, 0.025}; // Adjust dimensions as needed

            geometry_msgs::Pose box_pose;
            box_pose.position = box_position;
            box_pose.orientation = box_tracker.getBoxOrientation();
            collision_object.primitives.push_back(primitive);
            collision_object.primitive_poses.push_back(box_pose);
            collision_object.operation = collision_object.ADD;

            std::vector<moveit_msgs::CollisionObject> collision_objects = {collision_object};
            planning_scene_interface.applyCollisionObjects(collision_objects);

            // Move to the pick position
            box_pose.position.z += 0.1; // Adjust height for approaching
            move_group_interface_arm.setPoseTarget(box_pose);
            move_group_interface_arm.move();

            // Close the gripper to pick the object
            // Implement your gripper control logic here
            // e.g., gripper_interface.close();

            // Move the arm up after picking
            box_pose.position.z += 0.1; // Move up after picking
            move_group_interface_arm.setPoseTarget(box_pose);
            move_group_interface_arm.move();

            // Move to the place position (adjust these values as needed)
            geometry_msgs::Pose place_pose = box_pose;
            place_pose.position.x = 0.5; // Set your desired place position
            place_pose.position.y = 0.0;
            place_pose.position.z = 0.1; // Adjust height for placing

            move_group_interface_arm.setPoseTarget(place_pose);
            move_group_interface_arm.move();

            // Open the gripper to release the object
            // Implement your gripper control logic here
            // e.g., gripper_interface.open();

            // Clear the planning scene
            planning_scene_interface.removeCollisionObjects({collision_object.id});
        } else {
            ROS_INFO_STREAM("No box detected.");
        }

        ros::Duration(0.5).sleep(); // Sleep to prevent rapid processing
    }

    ros::shutdown();
    return 0;
}
