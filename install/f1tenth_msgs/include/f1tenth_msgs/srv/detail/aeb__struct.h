// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice

#ifndef F1TENTH_MSGS__SRV__DETAIL__AEB__STRUCT_H_
#define F1TENTH_MSGS__SRV__DETAIL__AEB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Aeb in the package f1tenth_msgs.
typedef struct f1tenth_msgs__srv__Aeb_Request
{
  double desired_distance;
  double ttc;
} f1tenth_msgs__srv__Aeb_Request;

// Struct for a sequence of f1tenth_msgs__srv__Aeb_Request.
typedef struct f1tenth_msgs__srv__Aeb_Request__Sequence
{
  f1tenth_msgs__srv__Aeb_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} f1tenth_msgs__srv__Aeb_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/Aeb in the package f1tenth_msgs.
typedef struct f1tenth_msgs__srv__Aeb_Response
{
  rosidl_runtime_c__String result;
} f1tenth_msgs__srv__Aeb_Response;

// Struct for a sequence of f1tenth_msgs__srv__Aeb_Response.
typedef struct f1tenth_msgs__srv__Aeb_Response__Sequence
{
  f1tenth_msgs__srv__Aeb_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} f1tenth_msgs__srv__Aeb_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // F1TENTH_MSGS__SRV__DETAIL__AEB__STRUCT_H_
