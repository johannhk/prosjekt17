// Generated by gencpp from file cyborg_controller/SystemState.msg
// DO NOT EDIT!


#ifndef CYBORG_CONTROLLER_MESSAGE_SYSTEMSTATE_H
#define CYBORG_CONTROLLER_MESSAGE_SYSTEMSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cyborg_controller
{
template <class ContainerAllocator>
struct SystemState_
{
  typedef SystemState_<ContainerAllocator> Type;

  SystemState_()
    : event()
    , from_system_state()
    , to_system_state()  {
    }
  SystemState_(const ContainerAllocator& _alloc)
    : event(_alloc)
    , from_system_state(_alloc)
    , to_system_state(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _event_type;
  _event_type event;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _from_system_state_type;
  _from_system_state_type from_system_state;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _to_system_state_type;
  _to_system_state_type to_system_state;




  typedef boost::shared_ptr< ::cyborg_controller::SystemState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cyborg_controller::SystemState_<ContainerAllocator> const> ConstPtr;

}; // struct SystemState_

typedef ::cyborg_controller::SystemState_<std::allocator<void> > SystemState;

typedef boost::shared_ptr< ::cyborg_controller::SystemState > SystemStatePtr;
typedef boost::shared_ptr< ::cyborg_controller::SystemState const> SystemStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cyborg_controller::SystemState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cyborg_controller::SystemState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cyborg_controller

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'cyborg_controller': ['/home/johs/prosjekt/temp_ws/src/cyborg_ros_controller/msg', '/home/johs/prosjekt/temp_ws/devel/share/cyborg_controller/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cyborg_controller::SystemState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cyborg_controller::SystemState_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cyborg_controller::SystemState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cyborg_controller::SystemState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cyborg_controller::SystemState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cyborg_controller::SystemState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cyborg_controller::SystemState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "33e4fca93c330d18c8a8d3b755c771c5";
  }

  static const char* value(const ::cyborg_controller::SystemState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x33e4fca93c330d18ULL;
  static const uint64_t static_value2 = 0xc8a8d3b755c771c5ULL;
};

template<class ContainerAllocator>
struct DataType< ::cyborg_controller::SystemState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cyborg_controller/SystemState";
  }

  static const char* value(const ::cyborg_controller::SystemState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cyborg_controller::SystemState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string event\n\
string from_system_state\n\
string to_system_state\n\
";
  }

  static const char* value(const ::cyborg_controller::SystemState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cyborg_controller::SystemState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.event);
      stream.next(m.from_system_state);
      stream.next(m.to_system_state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SystemState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cyborg_controller::SystemState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cyborg_controller::SystemState_<ContainerAllocator>& v)
  {
    s << indent << "event: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.event);
    s << indent << "from_system_state: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.from_system_state);
    s << indent << "to_system_state: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.to_system_state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CYBORG_CONTROLLER_MESSAGE_SYSTEMSTATE_H