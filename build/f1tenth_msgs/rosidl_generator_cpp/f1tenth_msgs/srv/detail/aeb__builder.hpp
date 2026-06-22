// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice

#ifndef F1TENTH_MSGS__SRV__DETAIL__AEB__BUILDER_HPP_
#define F1TENTH_MSGS__SRV__DETAIL__AEB__BUILDER_HPP_

#include "f1tenth_msgs/srv/detail/aeb__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace f1tenth_msgs
{

namespace srv
{

namespace builder
{

class Init_Aeb_Request_ttc
{
public:
  explicit Init_Aeb_Request_ttc(::f1tenth_msgs::srv::Aeb_Request & msg)
  : msg_(msg)
  {}
  ::f1tenth_msgs::srv::Aeb_Request ttc(::f1tenth_msgs::srv::Aeb_Request::_ttc_type arg)
  {
    msg_.ttc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::f1tenth_msgs::srv::Aeb_Request msg_;
};

class Init_Aeb_Request_desired_distance
{
public:
  Init_Aeb_Request_desired_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aeb_Request_ttc desired_distance(::f1tenth_msgs::srv::Aeb_Request::_desired_distance_type arg)
  {
    msg_.desired_distance = std::move(arg);
    return Init_Aeb_Request_ttc(msg_);
  }

private:
  ::f1tenth_msgs::srv::Aeb_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::f1tenth_msgs::srv::Aeb_Request>()
{
  return f1tenth_msgs::srv::builder::Init_Aeb_Request_desired_distance();
}

}  // namespace f1tenth_msgs


namespace f1tenth_msgs
{

namespace srv
{

namespace builder
{

class Init_Aeb_Response_result
{
public:
  Init_Aeb_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::f1tenth_msgs::srv::Aeb_Response result(::f1tenth_msgs::srv::Aeb_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::f1tenth_msgs::srv::Aeb_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::f1tenth_msgs::srv::Aeb_Response>()
{
  return f1tenth_msgs::srv::builder::Init_Aeb_Response_result();
}

}  // namespace f1tenth_msgs

#endif  // F1TENTH_MSGS__SRV__DETAIL__AEB__BUILDER_HPP_
