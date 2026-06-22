// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice

#ifndef F1TENTH_MSGS__SRV__DETAIL__AEB__STRUCT_HPP_
#define F1TENTH_MSGS__SRV__DETAIL__AEB__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__f1tenth_msgs__srv__Aeb_Request __attribute__((deprecated))
#else
# define DEPRECATED__f1tenth_msgs__srv__Aeb_Request __declspec(deprecated)
#endif

namespace f1tenth_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Aeb_Request_
{
  using Type = Aeb_Request_<ContainerAllocator>;

  explicit Aeb_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->desired_distance = 0.0;
      this->ttc = 0.0;
    }
  }

  explicit Aeb_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->desired_distance = 0.0;
      this->ttc = 0.0;
    }
  }

  // field types and members
  using _desired_distance_type =
    double;
  _desired_distance_type desired_distance;
  using _ttc_type =
    double;
  _ttc_type ttc;

  // setters for named parameter idiom
  Type & set__desired_distance(
    const double & _arg)
  {
    this->desired_distance = _arg;
    return *this;
  }
  Type & set__ttc(
    const double & _arg)
  {
    this->ttc = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__f1tenth_msgs__srv__Aeb_Request
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__f1tenth_msgs__srv__Aeb_Request
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Aeb_Request_ & other) const
  {
    if (this->desired_distance != other.desired_distance) {
      return false;
    }
    if (this->ttc != other.ttc) {
      return false;
    }
    return true;
  }
  bool operator!=(const Aeb_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Aeb_Request_

// alias to use template instance with default allocator
using Aeb_Request =
  f1tenth_msgs::srv::Aeb_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace f1tenth_msgs


#ifndef _WIN32
# define DEPRECATED__f1tenth_msgs__srv__Aeb_Response __attribute__((deprecated))
#else
# define DEPRECATED__f1tenth_msgs__srv__Aeb_Response __declspec(deprecated)
#endif

namespace f1tenth_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Aeb_Response_
{
  using Type = Aeb_Response_<ContainerAllocator>;

  explicit Aeb_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  explicit Aeb_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__f1tenth_msgs__srv__Aeb_Response
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__f1tenth_msgs__srv__Aeb_Response
    std::shared_ptr<f1tenth_msgs::srv::Aeb_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Aeb_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Aeb_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Aeb_Response_

// alias to use template instance with default allocator
using Aeb_Response =
  f1tenth_msgs::srv::Aeb_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace f1tenth_msgs

namespace f1tenth_msgs
{

namespace srv
{

struct Aeb
{
  using Request = f1tenth_msgs::srv::Aeb_Request;
  using Response = f1tenth_msgs::srv::Aeb_Response;
};

}  // namespace srv

}  // namespace f1tenth_msgs

#endif  // F1TENTH_MSGS__SRV__DETAIL__AEB__STRUCT_HPP_
