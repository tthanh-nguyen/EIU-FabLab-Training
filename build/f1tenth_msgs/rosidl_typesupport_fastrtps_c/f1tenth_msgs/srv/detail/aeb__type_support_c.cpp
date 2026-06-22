// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice
#include "f1tenth_msgs/srv/detail/aeb__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "f1tenth_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "f1tenth_msgs/srv/detail/aeb__struct.h"
#include "f1tenth_msgs/srv/detail/aeb__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Aeb_Request__ros_msg_type = f1tenth_msgs__srv__Aeb_Request;

static bool _Aeb_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Aeb_Request__ros_msg_type * ros_message = static_cast<const _Aeb_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: desired_distance
  {
    cdr << ros_message->desired_distance;
  }

  // Field name: ttc
  {
    cdr << ros_message->ttc;
  }

  return true;
}

static bool _Aeb_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Aeb_Request__ros_msg_type * ros_message = static_cast<_Aeb_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: desired_distance
  {
    cdr >> ros_message->desired_distance;
  }

  // Field name: ttc
  {
    cdr >> ros_message->ttc;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_f1tenth_msgs
size_t get_serialized_size_f1tenth_msgs__srv__Aeb_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Aeb_Request__ros_msg_type * ros_message = static_cast<const _Aeb_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name desired_distance
  {
    size_t item_size = sizeof(ros_message->desired_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ttc
  {
    size_t item_size = sizeof(ros_message->ttc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Aeb_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_f1tenth_msgs__srv__Aeb_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_f1tenth_msgs
size_t max_serialized_size_f1tenth_msgs__srv__Aeb_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: desired_distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ttc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Aeb_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_f1tenth_msgs__srv__Aeb_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Aeb_Request = {
  "f1tenth_msgs::srv",
  "Aeb_Request",
  _Aeb_Request__cdr_serialize,
  _Aeb_Request__cdr_deserialize,
  _Aeb_Request__get_serialized_size,
  _Aeb_Request__max_serialized_size
};

static rosidl_message_type_support_t _Aeb_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Aeb_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, f1tenth_msgs, srv, Aeb_Request)() {
  return &_Aeb_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "f1tenth_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "f1tenth_msgs/srv/detail/aeb__struct.h"
// already included above
// #include "f1tenth_msgs/srv/detail/aeb__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // result
#include "rosidl_runtime_c/string_functions.h"  // result

// forward declare type support functions


using _Aeb_Response__ros_msg_type = f1tenth_msgs__srv__Aeb_Response;

static bool _Aeb_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Aeb_Response__ros_msg_type * ros_message = static_cast<const _Aeb_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    const rosidl_runtime_c__String * str = &ros_message->result;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _Aeb_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Aeb_Response__ros_msg_type * ros_message = static_cast<_Aeb_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->result.data) {
      rosidl_runtime_c__String__init(&ros_message->result);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->result,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'result'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_f1tenth_msgs
size_t get_serialized_size_f1tenth_msgs__srv__Aeb_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Aeb_Response__ros_msg_type * ros_message = static_cast<const _Aeb_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name result
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->result.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Aeb_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_f1tenth_msgs__srv__Aeb_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_f1tenth_msgs
size_t max_serialized_size_f1tenth_msgs__srv__Aeb_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: result
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Aeb_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_f1tenth_msgs__srv__Aeb_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Aeb_Response = {
  "f1tenth_msgs::srv",
  "Aeb_Response",
  _Aeb_Response__cdr_serialize,
  _Aeb_Response__cdr_deserialize,
  _Aeb_Response__get_serialized_size,
  _Aeb_Response__max_serialized_size
};

static rosidl_message_type_support_t _Aeb_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Aeb_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, f1tenth_msgs, srv, Aeb_Response)() {
  return &_Aeb_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "f1tenth_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "f1tenth_msgs/srv/aeb.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Aeb__callbacks = {
  "f1tenth_msgs::srv",
  "Aeb",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, f1tenth_msgs, srv, Aeb_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, f1tenth_msgs, srv, Aeb_Response)(),
};

static rosidl_service_type_support_t Aeb__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Aeb__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, f1tenth_msgs, srv, Aeb)() {
  return &Aeb__handle;
}

#if defined(__cplusplus)
}
#endif
