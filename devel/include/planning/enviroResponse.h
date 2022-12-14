// Generated by gencpp from file planning/enviroResponse.msg
// DO NOT EDIT!


#ifndef PLANNING_MESSAGE_ENVIRORESPONSE_H
#define PLANNING_MESSAGE_ENVIRORESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace planning
{
template <class ContainerAllocator>
struct enviroResponse_
{
  typedef enviroResponse_<ContainerAllocator> Type;

  enviroResponse_()
    : response()  {
    }
  enviroResponse_(const ContainerAllocator& _alloc)
    : response(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _response_type;
  _response_type response;





  typedef boost::shared_ptr< ::planning::enviroResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::planning::enviroResponse_<ContainerAllocator> const> ConstPtr;

}; // struct enviroResponse_

typedef ::planning::enviroResponse_<std::allocator<void> > enviroResponse;

typedef boost::shared_ptr< ::planning::enviroResponse > enviroResponsePtr;
typedef boost::shared_ptr< ::planning::enviroResponse const> enviroResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::planning::enviroResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::planning::enviroResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::planning::enviroResponse_<ContainerAllocator1> & lhs, const ::planning::enviroResponse_<ContainerAllocator2> & rhs)
{
  return lhs.response == rhs.response;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::planning::enviroResponse_<ContainerAllocator1> & lhs, const ::planning::enviroResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace planning

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::planning::enviroResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning::enviroResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::planning::enviroResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::planning::enviroResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning::enviroResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning::enviroResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::planning::enviroResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6de314e2dc76fbff2b6244a6ad70b68d";
  }

  static const char* value(const ::planning::enviroResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6de314e2dc76fbffULL;
  static const uint64_t static_value2 = 0x2b6244a6ad70b68dULL;
};

template<class ContainerAllocator>
struct DataType< ::planning::enviroResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "planning/enviroResponse";
  }

  static const char* value(const ::planning::enviroResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::planning::enviroResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Response message types\n"
"string response\n"
"\n"
;
  }

  static const char* value(const ::planning::enviroResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::planning::enviroResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.response);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct enviroResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::planning::enviroResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::planning::enviroResponse_<ContainerAllocator>& v)
  {
    s << indent << "response: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.response);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PLANNING_MESSAGE_ENVIRORESPONSE_H
