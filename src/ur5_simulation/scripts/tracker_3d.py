#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
import cv2
import numpy as np

class RedBoxTracker(object):
    def __init__(self):
        self.publisher_ = rospy.Publisher('object_coordinates', String, queue_size=10)
        self.image_publisher_ = rospy.Publisher('object_tracking/image_raw', Image, queue_size=10)
        self.bridge = CvBridge()
        self.depth_image = None
        self.camera_info = None

        # Subscribe to color and depth image topics
        rospy.Subscriber('/camera/color/image_raw', Image, self.color_callback)
        rospy.Subscriber('/camera/depth/image_raw', Image, self.depth_callback)
        rospy.Subscriber('/camera/depth/camera_info', CameraInfo, self.camera_info_callback)

    def color_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        # Define the range of red color in HSV
        lower_red = np.array([0, 120, 70])
        upper_red = np.array([10, 255, 255])
        mask1 = cv2.inRange(hsv_frame, lower_red, upper_red)

        lower_red = np.array([170, 120, 70])
        upper_red = np.array([180, 255, 255])
        mask2 = cv2.inRange(hsv_frame, lower_red, upper_red)

        # Combine the masks to capture the full range of red
        red_mask = cv2.bitwise_or(mask1, mask2)

        # Find contours in the red mask
        contours, _ = cv2.findContours(red_mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        areas = [cv2.contourArea(c) for c in contours]

        if len(areas) < 1:
            self.publish_image(frame)
            return

        # Find the largest contour (assuming it's the red box)
        max_index = np.argmax(areas)
        cnt = contours[max_index]
        x, y, w, h = cv2.boundingRect(cnt)
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 3)

        x2 = x + int(w / 2)
        y2 = y + int(h / 2)
        cv2.circle(frame, (x2, y2), 4, (0, 255, 0), -1)

        # Calculate 3D coordinates if depth image is available
        if self.depth_image is not None and self.camera_info is not None:
            depth = self.depth_image[y2, x2]
            if np.isfinite(depth):
                # Convert pixel coordinates and depth to 3D coordinates
                K = np.array(self.camera_info.K).reshape(3, 3)
                x3d, y3d, z3d = self.pixel_to_3d(K, (x2, y2), depth)
                text = f"x: {x3d}, y: {y3d}, z: {z3d}"
                cv2.putText(frame, text, (x2 - 10, y2 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                self.publisher_.publish(text)

        self.publish_image(frame)

    def depth_callback(self, msg):
        self.depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')

    def camera_info_callback(self, msg):
        self.camera_info = msg

    def pixel_to_3d(self, K, pixel, depth):
        u, v = pixel
        fx, fy, cx, cy = K[0, 0], K[1, 1], K[0, 2], K[1, 2]
        x3d = (u - cx) * depth / fx
        y3d = (v - cy) * depth / fy
        z3d = depth
        return x3d, y3d, z3d

    def publish_image(self, frame):
        image_message = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        self.image_publisher_.publish(image_message)

def main():
    rospy.init_node('red_box_tracker', anonymous=True)
    red_box_tracker = RedBoxTracker()
    rospy.spin()

if __name__ == '__main__':
    main()