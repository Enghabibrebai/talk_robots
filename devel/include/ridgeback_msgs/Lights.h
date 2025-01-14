// Generated by gencpp from file ridgeback_msgs/Lights.msg
// DO NOT EDIT!


#ifndef RIDGEBACK_MSGS_MESSAGE_LIGHTS_H
#define RIDGEBACK_MSGS_MESSAGE_LIGHTS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ridgeback_msgs/RGB.h>

namespace ridgeback_msgs
{
template <class ContainerAllocator>
struct Lights_
{
  typedef Lights_<ContainerAllocator> Type;

  Lights_()
    : lights()  {
    }
  Lights_(const ContainerAllocator& _alloc)
    : lights()  {
  (void)_alloc;
      lights.assign( ::ridgeback_msgs::RGB_<ContainerAllocator> (_alloc));
  }



   typedef boost::array< ::ridgeback_msgs::RGB_<ContainerAllocator> , 8>  _lights_type;
  _lights_type lights;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(LIGHTS_FRONT_LEFT_UPPER)
  #undef LIGHTS_FRONT_LEFT_UPPER
#endif
#if defined(_WIN32) && defined(LIGHTS_FRONT_LEFT_LOWER)
  #undef LIGHTS_FRONT_LEFT_LOWER
#endif
#if defined(_WIN32) && defined(LIGHTS_FRONT_RIGHT_UPPER)
  #undef LIGHTS_FRONT_RIGHT_UPPER
#endif
#if defined(_WIN32) && defined(LIGHTS_FRONT_RIGHT_LOWER)
  #undef LIGHTS_FRONT_RIGHT_LOWER
#endif
#if defined(_WIN32) && defined(LIGHTS_REAR_LEFT_UPPER)
  #undef LIGHTS_REAR_LEFT_UPPER
#endif
#if defined(_WIN32) && defined(LIGHTS_REAR_LEFT_LOWER)
  #undef LIGHTS_REAR_LEFT_LOWER
#endif
#if defined(_WIN32) && defined(LIGHTS_REAR_RIGHT_UPPER)
  #undef LIGHTS_REAR_RIGHT_UPPER
#endif
#if defined(_WIN32) && defined(LIGHTS_REAR_RIGHT_LOWER)
  #undef LIGHTS_REAR_RIGHT_LOWER
#endif

  enum {
    LIGHTS_FRONT_LEFT_UPPER = 0u,
    LIGHTS_FRONT_LEFT_LOWER = 1u,
    LIGHTS_FRONT_RIGHT_UPPER = 2u,
    LIGHTS_FRONT_RIGHT_LOWER = 3u,
    LIGHTS_REAR_LEFT_UPPER = 4u,
    LIGHTS_REAR_LEFT_LOWER = 5u,
    LIGHTS_REAR_RIGHT_UPPER = 6u,
    LIGHTS_REAR_RIGHT_LOWER = 7u,
  };


  typedef boost::shared_ptr< ::ridgeback_msgs::Lights_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ridgeback_msgs::Lights_<ContainerAllocator> const> ConstPtr;

}; // struct Lights_

typedef ::ridgeback_msgs::Lights_<std::allocator<void> > Lights;

typedef boost::shared_ptr< ::ridgeback_msgs::Lights > LightsPtr;
typedef boost::shared_ptr< ::ridgeback_msgs::Lights const> LightsConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ridgeback_msgs::Lights_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ridgeback_msgs::Lights_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ridgeback_msgs::Lights_<ContainerAllocator1> & lhs, const ::ridgeback_msgs::Lights_<ContainerAllocator2> & rhs)
{
  return lhs.lights == rhs.lights;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ridgeback_msgs::Lights_<ContainerAllocator1> & lhs, const ::ridgeback_msgs::Lights_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ridgeback_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ridgeback_msgs::Lights_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ridgeback_msgs::Lights_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ridgeback_msgs::Lights_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ridgeback_msgs::Lights_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ridgeback_msgs::Lights_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ridgeback_msgs::Lights_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ridgeback_msgs::Lights_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2c68505ba4cf8e160d2760ed01777bc7";
  }

  static const char* value(const ::ridgeback_msgs::Lights_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2c68505ba4cf8e16ULL;
  static const uint64_t static_value2 = 0x0d2760ed01777bc7ULL;
};

template<class ContainerAllocator>
struct DataType< ::ridgeback_msgs::Lights_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ridgeback_msgs/Lights";
  }

  static const char* value(const ::ridgeback_msgs::Lights_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ridgeback_msgs::Lights_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Represents a command for the 8 RGB body lights on Ridgeback.\n"
"\n"
"uint8 LIGHTS_FRONT_LEFT_UPPER=0\n"
"uint8 LIGHTS_FRONT_LEFT_LOWER=1\n"
"uint8 LIGHTS_FRONT_RIGHT_UPPER=2\n"
"uint8 LIGHTS_FRONT_RIGHT_LOWER=3\n"
"uint8 LIGHTS_REAR_LEFT_UPPER=4\n"
"uint8 LIGHTS_REAR_LEFT_LOWER=5\n"
"uint8 LIGHTS_REAR_RIGHT_UPPER=6\n"
"uint8 LIGHTS_REAR_RIGHT_LOWER=7\n"
"\n"
"ridgeback_msgs/RGB[8] lights\n"
"\n"
"================================================================================\n"
"MSG: ridgeback_msgs/RGB\n"
"# Represents the intensity of a single RGB LED, either reported or commanded.\n"
"\n"
"float32 red\n"
"float32 green\n"
"float32 blue\n"
;
  }

  static const char* value(const ::ridgeback_msgs::Lights_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ridgeback_msgs::Lights_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.lights);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Lights_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ridgeback_msgs::Lights_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ridgeback_msgs::Lights_<ContainerAllocator>& v)
  {
    s << indent << "lights[]" << std::endl;
    for (size_t i = 0; i < v.lights.size(); ++i)
    {
      s << indent << "  lights[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ridgeback_msgs::RGB_<ContainerAllocator> >::stream(s, indent + "    ", v.lights[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // RIDGEBACK_MSGS_MESSAGE_LIGHTS_H
