#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <ros/ros.h>
#include <iostream>

const double tau = 2 * M_PI;

// Function to close the gripper
void close_gripper(moveit::planning_interface::MoveGroupInterface& move_gripper) {
    move_gripper.setJointValueTarget("robotiq_85_left_knuckle_joint", 0.785);
    move_gripper.move();
}

// Function to open the gripper
void open_gripper(moveit::planning_interface::MoveGroupInterface& move_gripper) {
    move_gripper.setJointValueTarget("robotiq_85_left_knuckle_joint", 0.0);
    move_gripper.move();
}

// Main function
int main(int argc, char **argv) {
    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    sleep(2.0);

    moveit::planning_interface::MoveGroupInterface group("ur5_arm");
    moveit::planning_interface::MoveGroupInterface gripper("gripper");
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    ros::Publisher display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    moveit_msgs::DisplayTrajectory display_trajectory;

    ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
    ROS_INFO("End effector: %s", group.getEndEffectorLink().c_str());

    // Call a service or topic to get the detected object position
    // For example, replace with actual service call or subscriber
    double x = 0.5;  // Replace with actual position
    double y = -0.14; // Replace with actual position
    double z = 0.8;   // Replace with actual position

    // Target position based on detected object
    geometry_msgs::Pose target_pose1;
    target_pose1.position.x = x;
    target_pose1.position.y = y;
    target_pose1.position.z = z;
    tf2::Quaternion orientation;
    orientation.setRPY(-tau, tau/4, tau/4);
    target_pose1.orientation = tf2::toMsg(orientation);
    group.setPoseTarget(target_pose1);

    // Visualize the planning
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::core::MoveItErrorCode success = group.plan(my_plan);
    ROS_INFO("Planning %s", success ? "succeeded" : "failed");

    // Move the arm
    group.move();

    ros::WallDuration(1.0).sleep();
    close_gripper(gripper);
    ros::WallDuration(1.0).sleep();
    open_gripper(gripper); // Optionally open after picking

    ros::shutdown();
    return 0;
}
