// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice

#ifndef F1TENTH_MSGS__SRV__DETAIL__AEB__TRAITS_HPP_
#define F1TENTH_MSGS__SRV__DETAIL__AEB__TRAITS_HPP_

#include "f1tenth_msgs/srv/detail/aeb__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<f1tenth_msgs::srv::Aeb_Request>()
{
  return "f1tenth_msgs::srv::Aeb_Request";
}

template<>
inline const char * name<f1tenth_msgs::srv::Aeb_Request>()
{
  return "f1tenth_msgs/srv/Aeb_Request";
}

template<>
struct has_fixed_size<f1tenth_msgs::srv::Aeb_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<f1tenth_msgs::srv::Aeb_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<f1tenth_msgs::srv::Aeb_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<f1tenth_msgs::srv::Aeb_Response>()
{
  return "f1tenth_msgs::srv::Aeb_Response";
}

template<>
inline const char * name<f1tenth_msgs::srv::Aeb_Response>()
{
  return "f1tenth_msgs/srv/Aeb_Response";
}

template<>
struct has_fixed_size<f1tenth_msgs::srv::Aeb_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<f1tenth_msgs::srv::Aeb_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<f1tenth_msgs::srv::Aeb_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<f1tenth_msgs::srv::Aeb>()
{
  return "f1tenth_msgs::srv::Aeb";
}

template<>
inline const char * name<f1tenth_msgs::srv::Aeb>()
{
  return "f1tenth_msgs/srv/Aeb";
}

template<>
struct has_fixed_size<f1tenth_msgs::srv::Aeb>
  : std::integral_constant<
    bool,
    has_fixed_size<f1tenth_msgs::srv::Aeb_Request>::value &&
    has_fixed_size<f1tenth_msgs::srv::Aeb_Response>::value
  >
{
};

template<>
struct has_bounded_size<f1tenth_msgs::srv::Aeb>
  : std::integral_constant<
    bool,
    has_bounded_size<f1tenth_msgs::srv::Aeb_Request>::value &&
    has_bounded_size<f1tenth_msgs::srv::Aeb_Response>::value
  >
{
};

template<>
struct is_service<f1tenth_msgs::srv::Aeb>
  : std::true_type
{
};

template<>
struct is_service_request<f1tenth_msgs::srv::Aeb_Request>
  : std::true_type
{
};

template<>
struct is_service_response<f1tenth_msgs::srv::Aeb_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // F1TENTH_MSGS__SRV__DETAIL__AEB__TRAITS_HPP_
