#!/usr/bin/env python3
import cv2
import numpy as np
import rospy
from sensor_msgs.msg import Image
from sensor_msgs.msg import CameraInfo

class ObjectDetector:
    def __init__(self):
        self.color_sub = rospy.Subscriber("/camera/color/image_raw", Image, self.color_callback)
        self.depth_sub = rospy.Subscriber("/camera/depth/image_raw", Image, self.depth_callback)
        self.camera_info_sub = rospy.Subscriber("/camera/color/camera_info", CameraInfo, self.camera_info_callback)

        self.depth_image = None
        self.camera_matrix = None

    def camera_info_callback(self, msg):
        self.camera_matrix = np.array(msg.K).reshape(3, 3)

    def depth_callback(self, msg):
        self.depth_image = self.convert_depth_image(msg)

    def convert_depth_image(self, msg):
        # Convert depth image to a numpy array
        depth = np.frombuffer(msg.data, np.float).reshape(msg.height, msg.width)
        return depth

    def color_callback(self, msg):
        color_image = self.convert_color_image(msg)
        if self.depth_image is not None and self.camera_matrix is not None:
            position = self.detect_red_box(color_image)
            if position:
                print(f"Detected position: {position}")

    def convert_color_image(self, msg):
        # Convert color image to a numpy array
        color = np.frombuffer(msg.data, np.uint8).reshape(msg.height, msg.width, 3)
        return color

    def detect_red_box(self, color_image):
        hsv = cv2.cvtColor(color_image, cv2.COLOR_BGR2HSV)
        lower_red = np.array([0, 100, 100])
        upper_red = np.array([10, 255, 255])
        mask1 = cv2.inRange(hsv, lower_red, upper_red)

        lower_red = np.array([160, 100, 100])
        upper_red = np.array([180, 255, 255])
        mask2 = cv2.inRange(hsv, lower_red, upper_red)

        mask = mask1 + mask2
        contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

        if contours:
            largest_contour = max(contours, key=cv2.contourArea)
            x, y, w, h = cv2.boundingRect(largest_contour)
            center_x = x + w // 2
            center_y = y + h // 2
            depth_value = self.depth_image[center_y, center_x]
            position_3D = self.convert_to_3D(center_x, center_y, depth_value)
            return position_3D
        return None

    def convert_to_3D(self, x, y, depth):
        # Convert pixel coordinates to 3D coordinates using the camera matrix
        fx = self.camera_matrix[0, 0]
        fy = self.camera_matrix[1, 1]
        cx = self.camera_matrix[0, 2]
        cy = self.camera_matrix[1, 2]
        z = depth
        x_3D = (x - cx) * z / fx
        y_3D = (y - cy) * z / fy
        return (x_3D, y_3D, z)

if __name__ == "__main__":
    rospy.init_node("object_detector")
    detector = ObjectDetector()
    rospy.spin()
