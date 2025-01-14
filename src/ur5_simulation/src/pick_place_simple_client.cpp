#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <ur5_simulation/GetPosition.h>

// Function to continuously get the box position and update waypoints
void trackBoxPosition(ros::NodeHandle &n, moveit::planning_interface::MoveGroupInterface &move_group_interface_arm, moveit::planning_interface::PlanningSceneInterface &planning_scene_interface) {
    ros::ServiceClient box_and_target_position_srv_client = n.serviceClient<ur5_simulation::GetPosition>("get_position");
    ur5_simulation::GetPosition srv;

    while (ros::ok()) {
        if (box_and_target_position_srv_client.call(srv)) {
            ROS_INFO_STREAM("3D target position (camera frame): x " << srv.response.x_position
                            << " y " << srv.response.y_position
                            << " z " << srv.response.z_position);

            // Update the target pose for the robot's end-effector
            geometry_msgs::PoseStamped current_pose = move_group_interface_arm.getCurrentPose("tool0");
            geometry_msgs::Pose target_pose;
            target_pose.orientation = current_pose.pose.orientation;
            target_pose.position.x = srv.response.x_position;
            target_pose.position.y = srv.response.y_position;
            target_pose.position.z = srv.response.z_position + 0.34; // Adjust height as needed

            // Add waypoints to the path
            std::vector<geometry_msgs::Pose> waypoints;
            waypoints.push_back(current_pose.pose);
            waypoints.push_back(target_pose);

            // Create a motion plan request
            moveit_msgs::RobotTrajectory trajectory;
            const double eef_step = 0.01; // Adjust the step size as needed
            double fraction = move_group_interface_arm.computeCartesianPath(waypoints, eef_step, trajectory);

            if (fraction == 1.0) {
                move_group_interface_arm.execute(trajectory);
            } else {
                ROS_WARN("The path is only %f complete", fraction);
            }
        } else {
            ROS_ERROR_STREAM("Failed to call get_position service");
        }
        ros::Duration(0.1).sleep(); // Adjust the tracking frequency as needed
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "pick_and_place_opencv");
    ros::NodeHandle n;

    // Start ROS Async Spinner
    ros::AsyncSpinner spinner(1);
    spinner.start();

    static const std::string PLANNING_GROUP_ARM = "ur5_arm";
    static const std::string PLANNING_GROUP_GRIPPER = "gripper";

    moveit::planning_interface::MoveGroupInterface move_group_interface_arm(PLANNING_GROUP_ARM);
    moveit::planning_interface::MoveGroupInterface move_group_interface_gripper(PLANNING_GROUP_GRIPPER);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    robot_model_loader::RobotModelLoaderPtr robot_model_loader(new robot_model_loader::RobotModelLoader("robot_description"));
    planning_scene_monitor::PlanningSceneMonitorPtr planning_scene_monitor(new planning_scene_monitor::PlanningSceneMonitor(robot_model_loader));

    // Allow collisions between the gripper and the box
    planning_scene_monitor::LockedPlanningSceneRW ls(planning_scene_monitor);
    collision_detection::AllowedCollisionMatrix& acm = ls->getAllowedCollisionMatrixNonConst();
    acm.setEntry("blue_box", "robotiq_85_left_finger_tip_link", true);
    acm.setEntry("blue_box", "robotiq_85_right_finger_tip_link", true);
    acm.setEntry("blue_box", "robotiq_85_right_inner_knuckle_link", true);
    acm.setEntry("blue_box", "robotiq_85_left_inner_knuckle_link", true);
    acm.setEntry("blue_box", "robotiq_85_base_link", true);
    acm.setEntry("blue_box", "robotiq_85_left_finger_link", true);
    acm.setEntry("blue_box", "robotiq_85_right_finger_link", true);
    acm.setEntry("blue_box", "robotiq_85_left_knuckle_link", true);
    acm.setEntry("blue_box", "robotiq_85_right_knuckle_link", true);

    std::cout << "\nAllowedCollisionMatrix:\n";
    acm.print(std::cout);
    moveit_msgs::PlanningScene diff_scene;
    ls->getPlanningSceneDiffMsg(diff_scene);
    planning_scene_interface.applyPlanningScene(diff_scene);

    ros::Duration(0.1).sleep();

    // Log available planning groups
    ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
    std::copy(move_group_interface_arm.getJointModelGroupNames().begin(),
              move_group_interface_arm.getJointModelGroupNames().end(),
              std::ostream_iterator<std::string>(std::cout, ", "));

    // Move to home position
    move_group_interface_arm.setJointValueTarget(move_group_interface_arm.getNamedTargetValues("home"));
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    bool success = (move_group_interface_arm.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    ROS_INFO_NAMED("tutorial", "Visualizing plan 1 (pose goal) %s", success ? "" : "FAILED");
    move_group_interface_arm.move();

    // Start tracking the box position and moving the robot
    trackBoxPosition(n, move_group_interface_arm, planning_scene_interface);

    ros::shutdown();
    return 0;
}