#pragma once

#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <opencv2/tracking.hpp>
#include <std_msgs/Bool.h>
#include <moveit/move_group_interface/move_group_interface.h> // Include MoveIt interface
#include <geometry_msgs/Pose.h>

class Tracker
{
public:
    Tracker();

private:
    void _imageCallback(const sensor_msgs::Image::ConstPtr& msg);
    void _initTracker(cv::Mat frame, cv::Rect2d& obj);
    void _moveToObject(const cv::Rect2d& obj);
    void _gripperControl(bool open);

    ros::NodeHandle nh; 
    ros::Subscriber _img_sub;
    ros::Publisher _visualization_pub;
    ros::Publisher _gripper_pub;
    cv::Ptr<cv::Tracker> _tracker;
    bool _is_tracker_initialized;

    moveit::planning_interface::MoveGroupInterface arm_group; // MoveIt interface for arm control
};
