#!/usr/bin/env python3
import rospy
import moveit_commander
from geometry_msgs.msg import Pose
import sys

def pick_and_place(target_position):
    moveit_commander.roscpp_initialize(sys.argv)
    rospy.init_node('pick_and_place', anonymous=True)

    arm = moveit_commander.MoveGroupCommander("ur5_arm")
    gripper = moveit_commander.MoveGroupCommander("gripper")

    # Move to above the object
    pick_position = target_position
    pick_position[2] += 0.1  # Adjust height for approach
    arm.set_position_target(pick_position)
    arm.go(wait=True)

    # Close gripper to pick the object
    gripper.set_joint_value_target([0.3])  # Closed position
    gripper.go(wait=True)

    # Move to the place position
    place_position = [0.5, 0.0, 0.0]  # Define your drop-off position
    arm.set_position_target(place_position)
    arm.go(wait=True)

    # Open gripper to release the object
    gripper.set_joint_value_target([0.0])  # Open position
    gripper.go(wait=True)

    moveit_commander.roscpp_shutdown()

if __name__ == "__main__":
    rospy.init_node('pick_and_place_node')
    target_position = (0.4, 0.0, 0.0)  # Example position, replace with detected position
    pick_and_place(target_position)
