// Generated by gencpp from file control_ur5/FilterScene.msg
// DO NOT EDIT!


#ifndef CONTROL_UR5_MESSAGE_FILTERSCENE_H
#define CONTROL_UR5_MESSAGE_FILTERSCENE_H

#include <ros/service_traits.h>


#include <control_ur5/FilterSceneRequest.h>
#include <control_ur5/FilterSceneResponse.h>


namespace control_ur5
{

struct FilterScene
{

typedef FilterSceneRequest Request;
typedef FilterSceneResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct FilterScene
} // namespace control_ur5


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::control_ur5::FilterScene > {
  static const char* value()
  {
    return "ea94d240c31365a6cbd92625f469bbdc";
  }

  static const char* value(const ::control_ur5::FilterScene&) { return value(); }
};

template<>
struct DataType< ::control_ur5::FilterScene > {
  static const char* value()
  {
    return "control_ur5/FilterScene";
  }

  static const char* value(const ::control_ur5::FilterScene&) { return value(); }
};


// service_traits::MD5Sum< ::control_ur5::FilterSceneRequest> should match
// service_traits::MD5Sum< ::control_ur5::FilterScene >
template<>
struct MD5Sum< ::control_ur5::FilterSceneRequest>
{
  static const char* value()
  {
    return MD5Sum< ::control_ur5::FilterScene >::value();
  }
  static const char* value(const ::control_ur5::FilterSceneRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::control_ur5::FilterSceneRequest> should match
// service_traits::DataType< ::control_ur5::FilterScene >
template<>
struct DataType< ::control_ur5::FilterSceneRequest>
{
  static const char* value()
  {
    return DataType< ::control_ur5::FilterScene >::value();
  }
  static const char* value(const ::control_ur5::FilterSceneRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::control_ur5::FilterSceneResponse> should match
// service_traits::MD5Sum< ::control_ur5::FilterScene >
template<>
struct MD5Sum< ::control_ur5::FilterSceneResponse>
{
  static const char* value()
  {
    return MD5Sum< ::control_ur5::FilterScene >::value();
  }
  static const char* value(const ::control_ur5::FilterSceneResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::control_ur5::FilterSceneResponse> should match
// service_traits::DataType< ::control_ur5::FilterScene >
template<>
struct DataType< ::control_ur5::FilterSceneResponse>
{
  static const char* value()
  {
    return DataType< ::control_ur5::FilterScene >::value();
  }
  static const char* value(const ::control_ur5::FilterSceneResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CONTROL_UR5_MESSAGE_FILTERSCENE_H
