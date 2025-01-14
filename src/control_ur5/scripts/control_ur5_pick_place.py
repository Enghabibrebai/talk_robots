#!/usr/bin/env python3

import sys
import rospy
import moveit_commander
from geometry_msgs.msg import Pose, PoseStamped
from std_srvs.srv import Empty
from control_ur5.srv import FilterScene, FilterSceneRequest
from sensor_msgs.msg import PointCloud2
from std_msgs.msg import Float32MultiArray

def update_octomap():
    """Update octomap in moveit planning scene."""
    clear_octomap.call()
    req = FilterSceneRequest()
    req.pointcloud_topic.data = '/camera/depth/color/points'
    req.image_topic.data = '/camera/color/image_raw'
    publish_octomap.call(req)

def object_callback(msg):
    """Callback function to handle object detection messages."""
    global object_position
    object_position = msg.data  # Assuming msg.data is [x, y, z] coordinates

if __name__ == "__main__":
    try:
        # Initialize moveit_commander and rosnode
        moveit_commander.roscpp_initialize(sys.argv)
        rospy.init_node('control_ur5', anonymous=False)
        
        # Octomap topics and services
        clear_octomap = rospy.ServiceProxy('/clear_octomap', Empty)
        publish_octomap = rospy.ServiceProxy('/filter_workspace', FilterScene)
        
        # Diagnostic publisher for waypoint poses
        pose_pub = rospy.Publisher('/checker', PoseStamped, latch=True, queue_size=5)
        
        # Initialize robot and move groups
        robot = moveit_commander.RobotCommander()
        arm_group = moveit_commander.MoveGroupCommander("ur5_arm")
        gripper_group = moveit_commander.MoveGroupCommander("gripper")

        rospy.sleep(2)
        
        # Initialize object detection subscriber
        rospy.Subscriber('/object_position', Float32MultiArray, object_callback)
        
        rospy.sleep(1)  # Give time for object detection initialization

        # Main loop
        while not rospy.is_shutdown():
            if 'object_position' in globals():
                # Update octomap
                update_octomap()
                
                # Define target pose based on detected object
                pose_goal = Pose()
                pose_goal.orientation = arm_group.get_current_pose().pose.orientation
                pose_goal.position.x = object_position[0]
                pose_goal.position.y = object_position[1]
                pose_goal.position.z = object_position[2]
                
                # Move to object
                arm_group.set_pose_target(pose_goal)
                plan = arm_group.plan()
                success = arm_group.execute(plan[1], wait=True)
                arm_group.stop()
                arm_group.clear_pose_targets()
                
                if success:
                    rospy.loginfo("Successfully moved to the object position.")
                    
                    # Open gripper
                    update_octomap()
                    open_gripper = [gripper_group.get_named_target_values('opened')['robotiq_85_left_knuckle_joint']]
                    gripper_group.go(open_gripper, wait=True)
                    gripper_group.stop()
                    
                    # Move to block
                    update_octomap()
                    arm_group.set_pose_target(pose_goal)
                    plan = arm_group.plan()
                    success = arm_group.execute(plan[1], wait=True)
                    arm_group.stop()
                    arm_group.clear_pose_targets()
                    
                    # Close gripper
                    update_octomap()
                    close_gripper = [gripper_group.get_named_target_values('closed')['robotiq_85_left_knuckle_joint']]
                    gripper_group.go(close_gripper, wait=True)
                    gripper_group.stop()
                    
                    # Lift block
                    update_octomap()
                    pose_goal.position.z += 0.2
                    arm_group.set_max_velocity_scaling_factor(0.1)
                    arm_group.set_pose_target(pose_goal)
                    plan = arm_group.plan()
                    success = arm_group.execute(plan[1], wait=True)
                    arm_group.stop()
                    arm_group.clear_pose_targets()
                    
                    # Move to opposite side
                    update_octomap()
                    pose_goal.position.x -= 1.2
                    arm_group.set_max_velocity_scaling_factor(0.2)
                    arm_group.set_pose_target(pose_goal)
                    plan = arm_group.plan()
                    success = arm_group.execute(plan[1], wait=True)
                    arm_group.stop()
                    arm_group.clear_pose_targets()
                    
                    # Release block
                    update_octomap()
                    gripper_group.go(open_gripper, wait=True)
                    gripper_group.stop()
                    
                    # Raise hand
                    update_octomap()
                    pose_goal.position.z += 0.2
                    arm_group.set_max_velocity_scaling_factor(0.1)
                    arm_group.set_pose_target(pose_goal)
                    plan = arm_group.plan()
                    success = arm_group.execute(plan[1], wait=True)
                    arm_group.stop()
                    arm_group.clear_pose_targets()
                    
                    # Return to home
                    update_octomap()
                    home_state = arm_group.get_current_state().joint_state
                    home_state.name = list(home_state.name)[:6]
                    home_state.position = [arm_group.get_named_target_values('home')['shoulder_pan_joint'],
                                            arm_group.get_named_target_values('home')['shoulder_lift_joint'],
                                            arm_group.get_named_target_values('home')['elbow_joint'],
                                            arm_group.get_named_target_values('home')['wrist_1_joint'],
                                            arm_group.get_named_target_values('home')['wrist_2_joint'],
                                            arm_group.get_named_target_values('home')['wrist_3_joint']]
                    plan = arm_group.plan(home_state)
                    success = arm_group.execute(plan[1], wait=True)
                    arm_group.stop()
                else:
                    rospy.logwarn("Failed to move to the object position.")
                
                rospy.sleep(1)  # Wait before next loop iteration
            
            rospy.sleep(0.1)  # Small sleep to prevent high CPU usage

    except rospy.ROSInterruptException:
        pass
    except KeyboardInterrupt:
        pass
