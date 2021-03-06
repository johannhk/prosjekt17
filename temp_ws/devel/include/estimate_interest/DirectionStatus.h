// Generated by gencpp from file estimate_interest/DirectionStatus.msg
// DO NOT EDIT!


#ifndef ESTIMATE_INTEREST_MESSAGE_DIRECTIONSTATUS_H
#define ESTIMATE_INTEREST_MESSAGE_DIRECTIONSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace estimate_interest
{
template <class ContainerAllocator>
struct DirectionStatus_
{
  typedef DirectionStatus_<ContainerAllocator> Type;

  DirectionStatus_()
    : direction()
    , interested(false)  {
    }
  DirectionStatus_(const ContainerAllocator& _alloc)
    : direction(_alloc)
    , interested(false)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _direction_type;
  _direction_type direction;

   typedef uint8_t _interested_type;
  _interested_type interested;




  typedef boost::shared_ptr< ::estimate_interest::DirectionStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::estimate_interest::DirectionStatus_<ContainerAllocator> const> ConstPtr;

}; // struct DirectionStatus_

typedef ::estimate_interest::DirectionStatus_<std::allocator<void> > DirectionStatus;

typedef boost::shared_ptr< ::estimate_interest::DirectionStatus > DirectionStatusPtr;
typedef boost::shared_ptr< ::estimate_interest::DirectionStatus const> DirectionStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::estimate_interest::DirectionStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::estimate_interest::DirectionStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace estimate_interest

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'estimate_interest': ['/home/johs/prosjekt/temp_ws/src/estimate_interest/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::estimate_interest::DirectionStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::estimate_interest::DirectionStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::estimate_interest::DirectionStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a5dd941b461c18d19ca708608d53c0ad";
  }

  static const char* value(const ::estimate_interest::DirectionStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa5dd941b461c18d1ULL;
  static const uint64_t static_value2 = 0x9ca708608d53c0adULL;
};

template<class ContainerAllocator>
struct DataType< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "estimate_interest/DirectionStatus";
  }

  static const char* value(const ::estimate_interest::DirectionStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string direction\n\
bool interested\n\
";
  }

  static const char* value(const ::estimate_interest::DirectionStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.direction);
      stream.next(m.interested);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DirectionStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::estimate_interest::DirectionStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::estimate_interest::DirectionStatus_<ContainerAllocator>& v)
  {
    s << indent << "direction: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.direction);
    s << indent << "interested: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.interested);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ESTIMATE_INTEREST_MESSAGE_DIRECTIONSTATUS_H
