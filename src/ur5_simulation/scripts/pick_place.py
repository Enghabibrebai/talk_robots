#!/usr/bin/env python3
import time
import geometry_msgs
import rospy
import sys
from tf.transformations import quaternion_from_euler
from geometry_msgs.msg import Pose, Point, Twist
import moveit_commander
from std_msgs.msg import String

# Initialize MoveIt
moveit_commander.roscpp_initialize(sys.argv)
robot = moveit_commander.RobotCommander()
scene = moveit_commander.PlanningSceneInterface()

arm_group = moveit_commander.MoveGroupCommander('ur5_arm')
gripper_group = moveit_commander.MoveGroupCommander('gripper')

class ObjectTracker:
    def __init__(self):
        self.object_pose = None
        self.subscriber = rospy.Subscriber('/object_pose_topic', geometry_msgs.msg.Pose, self.pose_callback)  # Adjust the topic name

    def pose_callback(self, msg):
        self.object_pose = msg

    def get_object_pose(self):
        return self.object_pose

class PickAndPlace:
    def __init__(self):
        self.arm_group = arm_group  # Replace with your arm group name
        self.gripper_group = gripper_group  # Replace with your gripper group name

    def move_to_pose(self, pose):
        self.arm_group.set_pose_target(pose)
        success, _ = self.arm_group.plan()
        if success:
            self.arm_group.move()

    def open_gripper(self):
        gripper_open_position = [0.085]  
        self.gripper_group.set_joint_value_target(gripper_open_position)
        self.gripper_group.plan()
        self.gripper_group.move()

    def close_gripper(self):
        gripper_closed_position = [0.0]  
        self.gripper_group.set_joint_value_target(gripper_closed_position)
        self.gripper_group.plan()
        self.gripper_group.move()

    def pick(self, object_pose):
        # Move to above the object
        pick_pose = geometry_msgs.msg.Pose()
        pick_pose.position = object_pose.position
        pick_pose.position.z += 0.9  # Move up to avoid collisions
        self.move_to_pose(pick_pose)
        self.close_gripper()  # Grasp the object

    def place(self, place_pose):
        self.move_to_pose(place_pose)
        self.open_gripper()  # Release the object

if __name__ == "__main__":
    rospy.init_node("pick_and_place_node")

    # Create the object tracker
    tracker = ObjectTracker()

    # Create the pick and place handler
    pick_and_place = PickAndPlace()

    # Wait for the object pose to be available
    while not rospy.is_shutdown():
        if tracker.get_object_pose() is not None:
            object_pose = tracker.get_object_pose()
            
            # Define a place pose
            place_pose = geometry_msgs.msg.Pose()
            place_pose.position.x = 1.5  # Set your desired place coordinates
            place_pose.position.y = 0.0
            place_pose.position.z = 0.8  # Adjust for the height
            
            # Execute pick and place
            pick_and_place.pick(object_pose)
            pick_and_place.place(place_pose)

            # Add a delay or condition to prevent rapid looping
            rospy.sleep(1)  # Adjust the sleep time as needed

    moveit_commander.roscpp_shutdown()



