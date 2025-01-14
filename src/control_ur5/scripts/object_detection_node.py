#!/usr/bin/env python3

import rospy
import cv2
import numpy as np
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge, CvBridgeError

class ObjectDetectionNode:
    def __init__(self):
        # Initialize ROS node
        rospy.init_node('object_detection_node', anonymous=True)
        
        # Initialize CvBridge
        self.bridge = CvBridge()
        
        # Publisher for object position
        self.object_position_pub = rospy.Publisher('/object_position', Float32MultiArray, queue_size=10)
        
        # Subscriber to camera feed
        self.image_sub = rospy.Subscriber('/camera/color/image_raw', Image, self.image_callback)
        
        rospy.loginfo("Object Detection Node Initialized")

    def image_callback(self, msg):
        """Callback function to process camera images."""
        try:
            # Convert ROS image message to OpenCV image
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError as e:
            rospy.logerr(f"CvBridgeError: {e}")
            return
        
        # Convert image to HSV color space
        hsv_image = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
        
        # Define color range for object detection (example range for green color)
        lower_bound = np.array([30, 150, 50])
        upper_bound = np.array([80, 255, 255])
        
        # Create a binary mask
        mask = cv2.inRange(hsv_image, lower_bound, upper_bound)
        
        # Find contours in the mask
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        
        if contours:
            # Find the largest contour
            largest_contour = max(contours, key=cv2.contourArea)
            
            # Compute the bounding box of the largest contour
            x, y, w, h = cv2.boundingRect(largest_contour)
            
            # Compute the center of the object
            object_x = x + w / 2
            object_y = y + h / 2
            
            # Publish object position
            object_position = Float32MultiArray()
            object_position.data = [object_x, object_y, 0.0]  # Assuming Z=0 for simplicity
            self.object_position_pub.publish(object_position)
            
            rospy.loginfo(f"Object Position: x={object_x}, y={object_y}")
        else:
            rospy.logwarn("No object detected")

if __name__ == '__main__':
    try:
        node = ObjectDetectionNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
 