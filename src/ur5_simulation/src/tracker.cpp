#include "ur5_simulation/tracker.h"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

Tracker::Tracker() 
    : nh(), 
      _is_tracker_initialized(false), 
      arm_group("ur5_arm") // Initialize arm group
{
    // Subscribers
    _img_sub = nh.subscribe("/camera/color/image_raw", 1, &Tracker::_imageCallback, this);

    // Publishers
    _visualization_pub = nh.advertise<sensor_msgs::Image>("/visualization", 1);
    _gripper_pub = nh.advertise<std_msgs::Bool>("gripper_cmd", 1);

    ROS_INFO("Node started!");
}

void Tracker::_imageCallback(const sensor_msgs::Image::ConstPtr& msg)
{
    // Convert the image message to an OpenCV Mat
    cv_bridge::CvImagePtr cv_image = cv_bridge::toCvCopy(msg, "bgr8");
    cv::Mat frame = cv_image->image;
    cv::Rect2d obj;

    // Color detection for the red box
    cv::Mat hsv_image, mask1, mask2;
    cv::cvtColor(frame, hsv_image, cv::COLOR_BGR2HSV);

    // Lower and Upper red HSV ranges
    cv::inRange(hsv_image, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), mask1);
    cv::inRange(hsv_image, cv::Scalar(160, 100, 100), cv::Scalar(180, 255, 255), mask2);
    cv::Mat mask = mask1 | mask2; // Combine masks

    // Debugging: Show the mask
    cv::imshow("Mask", mask);
    cv::waitKey(1); // Allow OpenCV to display the mask window

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    if (!contours.empty()) {
        // Get the largest contour
        size_t largest_contour_index = 0;
        double max_area = 0.0;
        for (size_t i = 0; i < contours.size(); ++i) {
            double area = cv::contourArea(contours[i]);
            if (area > max_area) {
                max_area = area;
                largest_contour_index = i;
            }
        }
        obj = cv::boundingRect(contours[largest_contour_index]); // Bounding box

        if (!_is_tracker_initialized) {
            _initTracker(frame, obj);
        }

        // Update tracker
        bool ok = _tracker->update(frame, obj);
        if (ok) {
            _moveToObject(obj);
        } else {
            ROS_WARN("Tracker update failed.");
        }
    } else {
        ROS_WARN("No contours detected.");
    }

    // Draw bounding box
    if (_is_tracker_initialized) {
        cv::rectangle(frame, obj, cv::Scalar(255, 0, 0), 2, 1);
    }
    
    cv_image->image = frame;
    auto img_msg = cv_image->toImageMsg();
    _visualization_pub.publish(img_msg);
}

void Tracker::_initTracker(cv::Mat frame, cv::Rect2d& obj)
{
    _tracker = cv::TrackerKCF::create(); // Create KCF tracker
    _tracker->init(frame, obj);
    _is_tracker_initialized = true;
}

void Tracker::_moveToObject(const cv::Rect2d& obj)
{
    // Convert the object's position to the robot's workspace
    geometry_msgs::Pose target_pose;
    
    // Adjust these values based on your setup
    target_pose.position.x = obj.x + obj.width / 2.0; // Center of the bounding box
    target_pose.position.y = obj.y + obj.height; // Just above the object
    target_pose.position.z = 0.8; // Height above conveyor
    target_pose.orientation.w = 1.0; // Neutral orientation

    // Debugging: Print target pose
    ROS_INFO_STREAM("Moving to position: [" << target_pose.position.x << ", "
                                             << target_pose.position.y << ", "
                                             << target_pose.position.z << "]");

    arm_group.setPoseTarget(target_pose);
    
    // Plan and execute the movement
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    bool success = (arm_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    
    if (success) {
        arm_group.move(); // Execute the planned movement
        // Control gripper
        _gripperControl(true); // Open gripper
        ros::Duration(1.0).sleep(); // Wait for a second
        _gripperControl(false); // Close gripper
    } else {
        ROS_WARN("Planning failed!");
    }
}

void Tracker::_gripperControl(bool opened)
{
    std_msgs::Bool gripper_msg;
    gripper_msg.data = opened;
    _gripper_pub.publish(gripper_msg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "tracker");
    Tracker tracker;
    ros::spin();
    return 0;
}
