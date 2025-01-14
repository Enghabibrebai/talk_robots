#!/usr/bin/env python3
import rospy
import cv2
import numpy as np
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

def nothing(pos):
    pass

def image_callback(msg):
    # Convertir le message ROS Image en image OpenCV
    cv_img = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
    
    # Converting frame (img i.e BGR) to HSV (hue-saturation-value)
    hsv = cv2.cvtColor(cv_img, cv2.COLOR_BGR2HSV)
    
    lh = cv2.getTrackbarPos('LH', 'Thresholds')
    ls = cv2.getTrackbarPos('LS', 'Thresholds')
    lv = cv2.getTrackbarPos('LV', 'Thresholds')

    uh = cv2.getTrackbarPos('UH', 'Thresholds')
    us = cv2.getTrackbarPos('US', 'Thresholds')
    uv = cv2.getTrackbarPos('UV', 'Thresholds')
    
    # Defining the range of color
    color_lower = np.array([lh, ls, lv], np.uint8)
    color_upper = np.array([uh, us, uv], np.uint8)
    
    # Finding the range of color in the image
    color = cv2.inRange(hsv, color_lower, color_upper)
    
    # Morphological transformation, Dilation
    kernal = np.ones((5, 5), "uint8")
    color = cv2.dilate(color, kernal)
           
    cv2.imshow("Color", color)
    cv2.imshow("Original Image", cv_img)	
    	 
    if cv2.waitKey(1) == ord('q'):
        rospy.signal_shutdown('Quit')

rospy.init_node('image_listener')
bridge = CvBridge()

cv2.namedWindow('Thresholds')
cv2.createTrackbar('LH', 'Thresholds', 0, 255, nothing)
cv2.createTrackbar('LS', 'Thresholds', 0, 255, nothing)
cv2.createTrackbar('LV', 'Thresholds', 0, 255, nothing)
cv2.createTrackbar('UH', 'Thresholds', 255, 255, nothing)
cv2.createTrackbar('US', 'Thresholds', 255, 255, nothing)
cv2.createTrackbar('UV', 'Thresholds', 255, 255, nothing)

# Abonnez-vous au topic de la caméra simulée
rospy.Subscriber('/camera/color/image_raw', Image, image_callback)

rospy.spin()
cv2.destroyAllWindows()