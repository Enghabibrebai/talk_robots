// Generated by gencpp from file intera_motion_msgs/MotionCommandGoal.msg
// DO NOT EDIT!


#ifndef INTERA_MOTION_MSGS_MESSAGE_MOTIONCOMMANDGOAL_H
#define INTERA_MOTION_MSGS_MESSAGE_MOTIONCOMMANDGOAL_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <intera_motion_msgs/Trajectory.h>

namespace intera_motion_msgs
{
template <class ContainerAllocator>
struct MotionCommandGoal_
{
  typedef MotionCommandGoal_<ContainerAllocator> Type;

  MotionCommandGoal_()
    : command()
    , trajectory()  {
    }
  MotionCommandGoal_(const ContainerAllocator& _alloc)
    : command(_alloc)
    , trajectory(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _command_type;
  _command_type command;

   typedef  ::intera_motion_msgs::Trajectory_<ContainerAllocator>  _trajectory_type;
  _trajectory_type trajectory;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(MOTION_START)
  #undef MOTION_START
#endif
#if defined(_WIN32) && defined(MOTION_STOP)
  #undef MOTION_STOP
#endif
#if defined(_WIN32) && defined(MOTION_GENERATE)
  #undef MOTION_GENERATE
#endif


  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> MOTION_START;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> MOTION_STOP;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> MOTION_GENERATE;

  typedef boost::shared_ptr< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> const> ConstPtr;

}; // struct MotionCommandGoal_

typedef ::intera_motion_msgs::MotionCommandGoal_<std::allocator<void> > MotionCommandGoal;

typedef boost::shared_ptr< ::intera_motion_msgs::MotionCommandGoal > MotionCommandGoalPtr;
typedef boost::shared_ptr< ::intera_motion_msgs::MotionCommandGoal const> MotionCommandGoalConstPtr;

// constants requiring out of line definition

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      MotionCommandGoal_<ContainerAllocator>::MOTION_START =
        
          "start"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      MotionCommandGoal_<ContainerAllocator>::MOTION_STOP =
        
          "stop"
        
        ;
   

   
   template<typename ContainerAllocator> const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
      MotionCommandGoal_<ContainerAllocator>::MOTION_GENERATE =
        
          "generate  # Generate path, but do not run"
        
        ;
   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator1> & lhs, const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator2> & rhs)
{
  return lhs.command == rhs.command &&
    lhs.trajectory == rhs.trajectory;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator1> & lhs, const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace intera_motion_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0b2003b52edbd59dd10da219c3a7fdb0";
  }

  static const char* value(const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0b2003b52edbd59dULL;
  static const uint64_t static_value2 = 0xd10da219c3a7fdb0ULL;
};

template<class ContainerAllocator>
struct DataType< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "intera_motion_msgs/MotionCommandGoal";
  }

  static const char* value(const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# Engine command goal\n"
"string command\n"
"string MOTION_START=start\n"
"string MOTION_STOP=stop\n"
"string MOTION_GENERATE=generate  # Generate path, but do not run\n"
"\n"
"Trajectory trajectory\n"
"\n"
"\n"
"================================================================================\n"
"MSG: intera_motion_msgs/Trajectory\n"
"# Representation of a trajectory used by the engine and motion controller.\n"
"\n"
"# optional label\n"
"string label\n"
"\n"
"# Array of joint names that correspond to the waypoint joint_positions\n"
"string[] joint_names\n"
"\n"
"# Array of waypoints that comprise the trajectory\n"
"Waypoint[] waypoints\n"
"\n"
"# Trajectory level options\n"
"TrajectoryOptions trajectory_options\n"
"================================================================================\n"
"MSG: intera_motion_msgs/Waypoint\n"
"# Representation of a waypoint used by the motion controller\n"
"\n"
"# Desired joint positions\n"
"# For Cartesian segments, the joint positions are used as nullspace biases\n"
"float64[] joint_positions\n"
"\n"
"# Name of the endpoint that is currently active\n"
"string active_endpoint\n"
"\n"
"# Cartesian pose\n"
"# This is not used in trajectories using joint interpolation\n"
"geometry_msgs/PoseStamped pose\n"
"\n"
"# Waypoint specific options\n"
"# Default values will be used if not set\n"
"# All waypoint options are applied to the segment moving to that waypoint\n"
"WaypointOptions options\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: intera_motion_msgs/WaypointOptions\n"
"# Optional waypoint label\n"
"string label\n"
"\n"
"# Ratio of max allowed joint speed : max planned joint speed (from 0.0 to 1.0)\n"
"float64 max_joint_speed_ratio\n"
"\n"
"# Slowdown heuristic is triggered if tracking error exceeds tolerances - radians\n"
"float64[] joint_tolerances\n"
"\n"
"# Maximum accelerations for each joint (only for joint paths) - rad/s^2.\n"
"float64[] max_joint_accel\n"
"\n"
"\n"
"###########################################################\n"
"# The remaining parameters only apply to Cartesian paths\n"
"\n"
"# Maximum linear speed of endpoint - m/s\n"
"float64 max_linear_speed\n"
"\n"
"# Maximum linear acceleration of endpoint - m/s^2\n"
"float64 max_linear_accel\n"
"\n"
"# Maximum rotational speed of endpoint - rad/s\n"
"float64 max_rotational_speed\n"
"\n"
"# Maximum rotational acceleration of endpoint - rad/s^2\n"
"float64 max_rotational_accel\n"
"\n"
"# Used for smoothing corners for continuous motion - m\n"
"# The distance from the waypoint to where the curve starts while blending from\n"
"# one straight line segment to the next.\n"
"# Larger distance:  trajectory passes farther from the waypoint at a higher speed\n"
"# Smaller distance:  trajectory passes closer to the waypoint at a lower speed\n"
"# Zero distance:  trajectory passes through the waypoint at zero speed\n"
"float64 corner_distance\n"
"\n"
"================================================================================\n"
"MSG: intera_motion_msgs/TrajectoryOptions\n"
"# Trajectory interpolation type\n"
"string CARTESIAN=CARTESIAN\n"
"string JOINT=JOINT\n"
"string interpolation_type\n"
"\n"
"# True if the trajectory uses interaction control, false for position control.\n"
"bool interaction_control\n"
"\n"
"# Interaction control parameters\n"
"intera_core_msgs/InteractionControlCommand interaction_params\n"
"\n"
"# Allow small joint adjustments at the beginning of Cartesian trajectories.\n"
"# Set to false for 'small' motions.\n"
"bool nso_start_offset_allowed\n"
"\n"
"# Check the offset at the end of a Cartesian trajectory from the final waypoint nullspace goal.\n"
"bool nso_check_end_offset\n"
"\n"
"# Options for the tracking controller:\n"
"TrackingOptions tracking_options\n"
"\n"
"# Desired trajectory end time, ROS timestamp\n"
"time end_time\n"
"\n"
"# The rate in seconds that the path is interpolated and returned back to the user\n"
"# No interpolation will happen if set to zero\n"
"float64 path_interpolation_step\n"
"\n"
"================================================================================\n"
"MSG: intera_core_msgs/InteractionControlCommand\n"
"# Message sets the interaction (impedance/force) control on or off\n"
"# It also contains desired cartesian stiffness K, damping D, and force values\n"
"\n"
"Header header\n"
"bool      interaction_control_active\n"
"\n"
"## Cartesian Impedance Control Parameters\n"
"# Stiffness units are (N/m) for first 3 and (Nm/rad) for second 3 values\n"
"float64[] K_impedance\n"
"# Force certain directions to have maximum possible impedance for a given pose\n"
"bool[] max_impedance\n"
"# Damping units are (Ns/m) for first 3 and (Nms/rad) for the second 3 values\n"
"float64[] D_impedance\n"
"# Joint Nullspace stiffness units are in (Nm/rad) (length == number of joints)\n"
"float64[] K_nullspace\n"
"\n"
"## Parameters for force control or impedance control with force limit\n"
"# If in force mode, this is the vector of desired forces/torques\n"
"# to be regulated in (N) and (Nm)\n"
"# If in impedance with force limit mode, this vector specifies the\n"
"# magnitude of forces/torques (N and Nm) that the command will not exceed.\n"
"float64[] force_command\n"
"\n"
"## Desired frame\n"
"geometry_msgs/Pose interaction_frame\n"
"string endpoint_name\n"
"# True if impedance and force commands are defined in endpoint frame\n"
"bool in_endpoint_frame\n"
"\n"
"# Set to true to disable damping during force control. Damping is used\n"
"# to slow down robot motion during force control in free space.\n"
"# Option included for SDK users to disable damping in force control\n"
"bool disable_damping_in_force_control\n"
"\n"
"# Set to true to disable reference resetting. Reference resetting is\n"
"# used when interaction parameters change, in order to avoid jumps/jerks.\n"
"# Option included for SDK users to disable reference resetting if the\n"
"# intention is to change interaction parameters.\n"
"bool disable_reference_resetting\n"
"\n"
"## Mode Selection Parameters\n"
"# The possible interaction control modes are:\n"
"# Impedance mode: implements desired endpoint stiffness and damping.\n"
"uint8 IMPEDANCE_MODE=1\n"
"# Force mode: applies force/torque in the specified dimensions.\n"
"uint8 FORCE_MODE=2\n"
"# Impedance with force limit: impedance control while ensuring the commanded\n"
"# forces/torques do not exceed force_command.\n"
"uint8 IMPEDANCE_WITH_FORCE_LIMIT_MODE=3\n"
"# Force with motion bounds: force control while ensuring the current\n"
"# pose/velocities do not exceed forceMotionThreshold (currenetly defined in yaml)\n"
"uint8 FORCE_WITH_MOTION_LIMIT_MODE=4\n"
"\n"
"# Specifies the interaction control mode for each Cartesian dimension (6)\n"
"uint8[] interaction_control_mode\n"
"\n"
"# All 6 values in force and impedance parameter vectors have to be filled,\n"
"# If a control mode is not used in a Cartesian dimension,\n"
"# the corresponding parameters will be ignored.\n"
"\n"
"## Parameters for Constrained Zero-G Behaviors\n"
"# Allow for arbitrary rotational displacements from the current orientation\n"
"# for constrained zero-G. Setting 'rotations_for_constrained_zeroG = True'\n"
"# will disable the rotational stiffness field which limits rotational\n"
"# displacements to +/- 82.5 degree.\n"
"# NOTE: it will be only enabled for a stationary reference orientation\n"
"bool rotations_for_constrained_zeroG\n"
"\n"
"================================================================================\n"
"MSG: intera_motion_msgs/TrackingOptions\n"
"# Minimum trajectory tracking time rate:  (default = less than one)\n"
"bool     use_min_time_rate\n"
"float64  min_time_rate\n"
"\n"
"# Maximum trajectory tracking time rate:  (1.0 = real-time = default)\n"
"bool     use_max_time_rate\n"
"float64  max_time_rate\n"
"\n"
"# Angular error tolerance at final point on trajectory (rad)\n"
"float64[] goal_joint_tolerance\n"
"\n"
"# Time for the controller to settle within joint tolerances at the goal (sec)\n"
"bool     use_settling_time_at_goal\n"
"float64  settling_time_at_goal\n"
;
  }

  static const char* value(const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
      stream.next(m.trajectory);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MotionCommandGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::intera_motion_msgs::MotionCommandGoal_<ContainerAllocator>& v)
  {
    s << indent << "command: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.command);
    s << indent << "trajectory: ";
    s << std::endl;
    Printer< ::intera_motion_msgs::Trajectory_<ContainerAllocator> >::stream(s, indent + "  ", v.trajectory);
  }
};

} // namespace message_operations
} // namespace ros

#endif // INTERA_MOTION_MSGS_MESSAGE_MOTIONCOMMANDGOAL_H
