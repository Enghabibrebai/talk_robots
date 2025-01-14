#!/usr/bin/env python3
import rospy
import cv2 as cv
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from moveit_commander import MoveGroupCommander, RobotCommander
from geometry_msgs.msg import PoseStamped
from tf.transformations import quaternion_from_euler

class ObjectDetection(object):
    def __init__(self):
        self.image_sub = rospy.Subscriber("/camera/color/image_raw", Image, self.camera_callback)
        self.bridge_object = CvBridge()
        self.robot = RobotCommander()
        self.arm_group = MoveGroupCommander("ur5_arm")
        self.gripper_group = MoveGroupCommander("gripper")
        
        # Camera calibration parameters (example values)
        self.camera_matrix = np.array([[600, 0, 320], [0, 600, 240], [0, 0, 1]])
        self.dist_coeffs = np.zeros(5)

        # Robot base frame and camera frame
        self.robot_base_frame = "base_link"
        self.camera_frame = "camera_link"

        # Conversion factors
        self.pxl_mm_conversion = 27/20
        self.x0 = 1000
        self.y0 = 0
        self.z0 = 500

        # Set planning parameters
        self.arm_group.set_planning_time(10.0)  # Increase planning time

    def camera_callback(self, data):
        try:
            cv_image = self.bridge_object.imgmsg_to_cv2(data, desired_encoding="bgr8")
        except CvBridgeError as e:
            print(e)

        hsv = cv.cvtColor(cv_image, cv.COLOR_BGR2HSV)
        min_red = np.array([0, 189, 166])
        max_red = np.array([0, 250, 255])

        mask_r = cv.inRange(hsv, min_red, max_red)
        mask = cv.adaptiveThreshold(mask_r, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY_INV, 3, 3)

        contours, _ = cv.findContours(mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

        for cnt in contours:
            area = cv.contourArea(cnt)
            if area > 20:
                rect = cv.minAreaRect(cnt)
                (x_center, y_center), (w,h), orientation = rect
                self.update_object_position(x_center, y_center)

    def update_object_position(self, x_center, y_center):
        x_robot, y_robot, z_robot = self.convert_to_robot_coordinates(x_center, y_center)
        self.pick_and_place(x_robot, y_robot, z_robot)

    def convert_to_robot_coordinates(self, x_center, y_center):
        # Convert pixel coordinates to 3D coordinates using camera calibration
        (u, v) = (x_center, y_center)
        z = self.z0  # Assuming the object is at a fixed depth
        x = (u - self.camera_matrix[0, 2]) * z / self.camera_matrix[0, 0]
        y = (v - self.camera_matrix[1, 2]) * z / self.camera_matrix[1, 1]

        # Convert from camera frame to robot base frame
        # This step requires knowing the transformation between the camera and robot base frames
        # For simplicity, we're assuming the camera is at the robot base frame
        x_robot = self.x0 + x / self.pxl_mm_conversion
        y_robot = self.y0 + y / self.pxl_mm_conversion
        z_robot = z

        return x_robot, y_robot, z_robot

    def pick_and_place(self, x, y, z):
        # Update the planning scene with the current robot state
        self.arm_group.set_start_state_to_current_state()

        # Set the target pose for the robot's end-effector
        target_pose = PoseStamped()
        target_pose.header.frame_id = self.robot_base_frame
        target_pose.pose.position.x = x
        target_pose.pose.position.y = y
        target_pose.pose.position.z = z

        # Set the orientation of the end-effector (example: straight down)
        quaternion = quaternion_from_euler(0, 0, np.pi)  # Roll, Pitch, Yaw in radians
        target_pose.pose.orientation.x = quaternion[0]
        target_pose.pose.orientation.y = quaternion[1]
        target_pose.pose.orientation.z = quaternion[2]
        target_pose.pose.orientation.w = quaternion[3]

        # Plan and execute the motion
        self.arm_group.set_pose_target(target_pose.pose)
        plan, planning_result, success = self.arm_group.plan()
        if success:
            self.arm_group.execute(plan)
        else:
            rospy.logerr("Planning failed")

        # Open the gripper
        self.gripper_group.set_named_target("opened")
        self.gripper_group.go()

        # Close the gripper
        self.gripper_group.set_named_target("closed")
        self.gripper_group.go()

        # Move to a safe place
        safe_pose = self.arm_group.get_named_target_values("safe_pose")
        self.arm_group.set_joint_value_target(safe_pose)
        self.arm_group.go()

if __name__ == '__main__':
    rospy.init_node('object_detection', anonymous=True)
    object_detection = ObjectDetection()
    rospy.spin()