#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class RedBoxTracker(object):
    def __init__(self):
        self.publisher_ = rospy.Publisher('object_coordinates', String, queue_size=10)
        self.image_publisher_ = rospy.Publisher('object_tracking/image_raw', Image, queue_size=10)
        self.bridge = CvBridge()

    def image_callback(self, msg):
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

        text = "x: " + str(x2) + ", y: " + str(y2)
        cv2.putText(frame, text, (x2 - 10, y2 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
        self.publisher_.publish(text)

        self.publish_image(frame)

    def publish_image(self, frame):
        image_message = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        self.image_publisher_.publish(image_message)

def main():
    rospy.init_node('red_box_tracker', anonymous=True)
    red_box_tracker = RedBoxTracker()
    rospy.Subscriber('/camera/color/image_raw', Image, red_box_tracker.image_callback)
    rospy.spin()

if __name__ == '__main__':
    main()