// Generated by gencpp from file cyborg_controller/EmotionalStateService.msg
// DO NOT EDIT!


#ifndef CYBORG_CONTROLLER_MESSAGE_EMOTIONALSTATESERVICE_H
#define CYBORG_CONTROLLER_MESSAGE_EMOTIONALSTATESERVICE_H

#include <ros/service_traits.h>


#include <cyborg_controller/EmotionalStateServiceRequest.h>
#include <cyborg_controller/EmotionalStateServiceResponse.h>


namespace cyborg_controller
{

struct EmotionalStateService
{

typedef EmotionalStateServiceRequest Request;
typedef EmotionalStateServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct EmotionalStateService
} // namespace cyborg_controller


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::cyborg_controller::EmotionalStateService > {
  static const char* value()
  {
    return "68da7087fb08817fd317a07916f3d49f";
  }

  static const char* value(const ::cyborg_controller::EmotionalStateService&) { return value(); }
};

template<>
struct DataType< ::cyborg_controller::EmotionalStateService > {
  static const char* value()
  {
    return "cyborg_controller/EmotionalStateService";
  }

  static const char* value(const ::cyborg_controller::EmotionalStateService&) { return value(); }
};


// service_traits::MD5Sum< ::cyborg_controller::EmotionalStateServiceRequest> should match 
// service_traits::MD5Sum< ::cyborg_controller::EmotionalStateService > 
template<>
struct MD5Sum< ::cyborg_controller::EmotionalStateServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::cyborg_controller::EmotionalStateService >::value();
  }
  static const char* value(const ::cyborg_controller::EmotionalStateServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::cyborg_controller::EmotionalStateServiceRequest> should match 
// service_traits::DataType< ::cyborg_controller::EmotionalStateService > 
template<>
struct DataType< ::cyborg_controller::EmotionalStateServiceRequest>
{
  static const char* value()
  {
    return DataType< ::cyborg_controller::EmotionalStateService >::value();
  }
  static const char* value(const ::cyborg_controller::EmotionalStateServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::cyborg_controller::EmotionalStateServiceResponse> should match 
// service_traits::MD5Sum< ::cyborg_controller::EmotionalStateService > 
template<>
struct MD5Sum< ::cyborg_controller::EmotionalStateServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::cyborg_controller::EmotionalStateService >::value();
  }
  static const char* value(const ::cyborg_controller::EmotionalStateServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::cyborg_controller::EmotionalStateServiceResponse> should match 
// service_traits::DataType< ::cyborg_controller::EmotionalStateService > 
template<>
struct DataType< ::cyborg_controller::EmotionalStateServiceResponse>
{
  static const char* value()
  {
    return DataType< ::cyborg_controller::EmotionalStateService >::value();
  }
  static const char* value(const ::cyborg_controller::EmotionalStateServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CYBORG_CONTROLLER_MESSAGE_EMOTIONALSTATESERVICE_H
