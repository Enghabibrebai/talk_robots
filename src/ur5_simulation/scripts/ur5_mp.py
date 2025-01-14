#!/usr/bin/env python

import rospy
import sys
import numpy as np
import moveit_commander
from copy import deepcopy
from ur5_simulation.msg import Tracker
from geometry_msgs.msg import Pose
from trajectory_msgs.msg import JointTrajectoryPoint

class ur5_mp:
    def __init__(self):
        rospy.init_node("ur5_mp", anonymous=False)
        self.cxy_sub = rospy.Subscriber('cxy', Tracker, self.tracking_callback, queue_size=1)
        self.cxy_pub = rospy.Publisher('cxy1', Tracker, queue_size=1)

        self.phase = 1
        self.object_cnt = 0
        self.track_flag = False
        self.default_pose_flag = True
        self.cx = 400.0
        self.cy = 400.0
        self.points = []
        self.state_change_time = rospy.Time.now()

        self.pointx = []
        self.pointy = []

        rospy.loginfo("Starting node moveit_cartesian_path")

        rospy.on_shutdown(self.cleanup)

        moveit_commander.roscpp_initialize(sys.argv)
        self.arm = moveit_commander.MoveGroupCommander('ur5_arm')
        self.end_effector_link = self.arm.get_end_effector_link()

        # Setup reference frame
        self.arm.set_pose_reference_frame("/base_link")
        self.arm.allow_replanning(True)
        self.arm.set_goal_position_tolerance(0.01)
        self.arm.set_goal_orientation_tolerance(0.1)
        self.arm.set_planning_time(5.0)  # Increased planning time
        self.arm.set_max_acceleration_scaling_factor(.5)
        self.arm.set_max_velocity_scaling_factor(.5)

        # Set default joint states
        self.default_joint_states = self.arm.get_current_joint_values()
        self.set_default_joint_states()

        # Set the initial waypoints
        self.initialize_waypoints()

    def set_default_joint_states(self):
        self.default_joint_states[0] = -1.57691
        self.default_joint_states[1] = -1.71667
        self.default_joint_states[2] = 1.79266
        self.default_joint_states[3] = -1.67721
        self.default_joint_states[4] = -1.5705
        self.default_joint_states[5] = 0.0

        self.arm.set_joint_value_target(self.default_joint_states)
        plan, success = self.arm.plan()  # Unpack the plan and success flag

    # Check if planning was successful
        if not success or not plan.joint_trajectory.points:
            rospy.logerr("Planning failed: no valid plan generated.")
            return  # Exit if planning failed

        self.arm.execute(plan)

    def initialize_waypoints(self):
        start_pose = self.arm.get_current_pose(self.end_effector_link).pose
        wpose = deepcopy(start_pose)
        wpose.position.x = -0.2
        wpose.position.y = -0.2
        wpose.position.z = 0.3
        self.waypoints = [deepcopy(wpose)]

    def cleanup(self):
        rospy.loginfo("Stopping the robot")
        self.arm.stop()
        rospy.loginfo("Shutting down Moveit!")
        moveit_commander.roscpp_shutdown()
        moveit_commander.os._exit(0)

    def tracking_callback(self, msg):
        self.track_flag = msg.flag1
        self.cx = msg.x
        self.cy = msg.y
        self.error_x = msg.error_x
        self.error_y = msg.error_y

        if len(self.pointx) > 9:
            self.track_flag = True
        
        if self.phase == 2:
            self.track_flag = False
            self.phase = 1

        if (self.track_flag and -0.6 < self.waypoints[0].position.x < 0.6):
            self.execute()
            self.default_pose_flag = False
        else:
            if not self.default_pose_flag:
                self.track_flag = False
                self.execute()
                self.default_pose_flag = True

    def execute(self):
        if self.track_flag:
            start_pose = self.arm.get_current_pose(self.end_effector_link).pose
            wpose = deepcopy(start_pose)

            if len(self.pointx) > 8:
                self.adjust_waypoint(wpose)
            else:
                self.default_waypoint(wpose)

            self.waypoints.append(deepcopy(wpose))
            self.arm.set_start_state_to_current_state()

            plan, fraction = self.arm.compute_cartesian_path(self.waypoints, 0.01, 0.0, True)

            # Check if planning was successful
            if 1 - fraction < 0.2:
                rospy.loginfo("Path computed successfully. Moving the arm.")
                self.arm.execute(plan)
            else:
                rospy.loginfo("Path planning failed with fraction: %f", fraction)
        else:
            self.default_pose()

    def adjust_waypoint(self, wpose):
        if len(self.pointx) == 9:
            x_speed = np.mean(np.asarray(self.pointx[4:8]) - np.asarray(self.pointx[3:7]))
            wpose.position.x += 2 * x_speed
            wpose.position.z = 0.05
        elif len(self.pointx) < 12:
            x_speed = np.mean(np.asarray(self.pointx[4:8]) - np.asarray(self.pointx[3:7]))
            wpose.position.x += (x_speed - self.error_x * 0.015 / 105)

    def default_waypoint(self, wpose):
        wpose.position.x -= self.error_x * 0.05 / 105
        wpose.position.y += self.error_y * 0.04 / 105
        wpose.position.z = 0.15

    def default_pose(self):
        start_pose = self.arm.get_current_pose(self.end_effector_link).pose
        wpose = deepcopy(start_pose)
        wpose.position.x = 0.1052
        wpose.position.y = -0.4271
        wpose.position.z = 0.4005

        # Set orientation (if needed)
        wpose.orientation.x = 0.4811
        wpose.orientation.y = 0.4994
        wpose.orientation.z = -0.5121
        wpose.orientation.w = 0.5069

        self.waypoints.append(deepcopy(wpose))
        self.arm.set_start_state_to_current_state()
        plan, fraction = self.arm.compute_cartesian_path(self.waypoints, 0.01, 0.0, True)

        # Check if planning was successful
        if 1 - fraction < 0.2:
            rospy.loginfo("Path computed successfully. Moving the arm.")
            self.arm.execute(plan)
        else:
            rospy.loginfo("Path planning failed with fraction: %f", fraction)

if __name__ == "__main__":
    mp = ur5_mp()
    rospy.spin()
