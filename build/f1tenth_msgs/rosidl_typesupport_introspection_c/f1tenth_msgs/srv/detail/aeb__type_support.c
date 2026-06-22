// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "f1tenth_msgs/srv/detail/aeb__rosidl_typesupport_introspection_c.h"
#include "f1tenth_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "f1tenth_msgs/srv/detail/aeb__functions.h"
#include "f1tenth_msgs/srv/detail/aeb__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  f1tenth_msgs__srv__Aeb_Request__init(message_memory);
}

void Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_fini_function(void * message_memory)
{
  f1tenth_msgs__srv__Aeb_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_member_array[2] = {
  {
    "desired_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(f1tenth_msgs__srv__Aeb_Request, desired_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ttc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(f1tenth_msgs__srv__Aeb_Request, ttc),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_members = {
  "f1tenth_msgs__srv",  // message namespace
  "Aeb_Request",  // message name
  2,  // number of fields
  sizeof(f1tenth_msgs__srv__Aeb_Request),
  Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_member_array,  // message members
  Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_type_support_handle = {
  0,
  &Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_f1tenth_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, f1tenth_msgs, srv, Aeb_Request)() {
  if (!Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_type_support_handle.typesupport_identifier) {
    Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Aeb_Request__rosidl_typesupport_introspection_c__Aeb_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "f1tenth_msgs/srv/detail/aeb__rosidl_typesupport_introspection_c.h"
// already included above
// #include "f1tenth_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "f1tenth_msgs/srv/detail/aeb__functions.h"
// already included above
// #include "f1tenth_msgs/srv/detail/aeb__struct.h"


// Include directives for member types
// Member `result`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  f1tenth_msgs__srv__Aeb_Response__init(message_memory);
}

void Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_fini_function(void * message_memory)
{
  f1tenth_msgs__srv__Aeb_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(f1tenth_msgs__srv__Aeb_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_members = {
  "f1tenth_msgs__srv",  // message namespace
  "Aeb_Response",  // message name
  1,  // number of fields
  sizeof(f1tenth_msgs__srv__Aeb_Response),
  Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_member_array,  // message members
  Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_type_support_handle = {
  0,
  &Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_f1tenth_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, f1tenth_msgs, srv, Aeb_Response)() {
  if (!Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_type_support_handle.typesupport_identifier) {
    Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Aeb_Response__rosidl_typesupport_introspection_c__Aeb_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "f1tenth_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "f1tenth_msgs/srv/detail/aeb__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_service_members = {
  "f1tenth_msgs__srv",  // service namespace
  "Aeb",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_Request_message_type_support_handle,
  NULL  // response message
  // f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_Response_message_type_support_handle
};

static rosidl_service_type_support_t f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_service_type_support_handle = {
  0,
  &f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, f1tenth_msgs, srv, Aeb_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, f1tenth_msgs, srv, Aeb_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_f1tenth_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, f1tenth_msgs, srv, Aeb)() {
  if (!f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_service_type_support_handle.typesupport_identifier) {
    f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, f1tenth_msgs, srv, Aeb_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, f1tenth_msgs, srv, Aeb_Response)()->data;
  }

  return &f1tenth_msgs__srv__detail__aeb__rosidl_typesupport_introspection_c__Aeb_service_type_support_handle;
}
