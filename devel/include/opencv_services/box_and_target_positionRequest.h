// Generated by gencpp from file opencv_services/box_and_target_positionRequest.msg
// DO NOT EDIT!


#ifndef OPENCV_SERVICES_MESSAGE_BOX_AND_TARGET_POSITIONREQUEST_H
#define OPENCV_SERVICES_MESSAGE_BOX_AND_TARGET_POSITIONREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace opencv_services
{
template <class ContainerAllocator>
struct box_and_target_positionRequest_
{
  typedef box_and_target_positionRequest_<ContainerAllocator> Type;

  box_and_target_positionRequest_()
    {
    }
  box_and_target_positionRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct box_and_target_positionRequest_

typedef ::opencv_services::box_and_target_positionRequest_<std::allocator<void> > box_and_target_positionRequest;

typedef boost::shared_ptr< ::opencv_services::box_and_target_positionRequest > box_and_target_positionRequestPtr;
typedef boost::shared_ptr< ::opencv_services::box_and_target_positionRequest const> box_and_target_positionRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace opencv_services

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::opencv_services::box_and_target_positionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "opencv_services/box_and_target_positionRequest";
  }

  static const char* value(const ::opencv_services::box_and_target_positionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::opencv_services::box_and_target_positionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct box_and_target_positionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::opencv_services::box_and_target_positionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::opencv_services::box_and_target_positionRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // OPENCV_SERVICES_MESSAGE_BOX_AND_TARGET_POSITIONREQUEST_H
