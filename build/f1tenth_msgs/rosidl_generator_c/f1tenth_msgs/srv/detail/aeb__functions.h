// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice

#ifndef F1TENTH_MSGS__SRV__DETAIL__AEB__FUNCTIONS_H_
#define F1TENTH_MSGS__SRV__DETAIL__AEB__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "f1tenth_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "f1tenth_msgs/srv/detail/aeb__struct.h"

/// Initialize srv/Aeb message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * f1tenth_msgs__srv__Aeb_Request
 * )) before or use
 * f1tenth_msgs__srv__Aeb_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Request__init(f1tenth_msgs__srv__Aeb_Request * msg);

/// Finalize srv/Aeb message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Request__fini(f1tenth_msgs__srv__Aeb_Request * msg);

/// Create srv/Aeb message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * f1tenth_msgs__srv__Aeb_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
f1tenth_msgs__srv__Aeb_Request *
f1tenth_msgs__srv__Aeb_Request__create();

/// Destroy srv/Aeb message.
/**
 * It calls
 * f1tenth_msgs__srv__Aeb_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Request__destroy(f1tenth_msgs__srv__Aeb_Request * msg);

/// Check for srv/Aeb message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Request__are_equal(const f1tenth_msgs__srv__Aeb_Request * lhs, const f1tenth_msgs__srv__Aeb_Request * rhs);

/// Copy a srv/Aeb message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Request__copy(
  const f1tenth_msgs__srv__Aeb_Request * input,
  f1tenth_msgs__srv__Aeb_Request * output);

/// Initialize array of srv/Aeb messages.
/**
 * It allocates the memory for the number of elements and calls
 * f1tenth_msgs__srv__Aeb_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Request__Sequence__init(f1tenth_msgs__srv__Aeb_Request__Sequence * array, size_t size);

/// Finalize array of srv/Aeb messages.
/**
 * It calls
 * f1tenth_msgs__srv__Aeb_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Request__Sequence__fini(f1tenth_msgs__srv__Aeb_Request__Sequence * array);

/// Create array of srv/Aeb messages.
/**
 * It allocates the memory for the array and calls
 * f1tenth_msgs__srv__Aeb_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
f1tenth_msgs__srv__Aeb_Request__Sequence *
f1tenth_msgs__srv__Aeb_Request__Sequence__create(size_t size);

/// Destroy array of srv/Aeb messages.
/**
 * It calls
 * f1tenth_msgs__srv__Aeb_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Request__Sequence__destroy(f1tenth_msgs__srv__Aeb_Request__Sequence * array);

/// Check for srv/Aeb message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Request__Sequence__are_equal(const f1tenth_msgs__srv__Aeb_Request__Sequence * lhs, const f1tenth_msgs__srv__Aeb_Request__Sequence * rhs);

/// Copy an array of srv/Aeb messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Request__Sequence__copy(
  const f1tenth_msgs__srv__Aeb_Request__Sequence * input,
  f1tenth_msgs__srv__Aeb_Request__Sequence * output);

/// Initialize srv/Aeb message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * f1tenth_msgs__srv__Aeb_Response
 * )) before or use
 * f1tenth_msgs__srv__Aeb_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Response__init(f1tenth_msgs__srv__Aeb_Response * msg);

/// Finalize srv/Aeb message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Response__fini(f1tenth_msgs__srv__Aeb_Response * msg);

/// Create srv/Aeb message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * f1tenth_msgs__srv__Aeb_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
f1tenth_msgs__srv__Aeb_Response *
f1tenth_msgs__srv__Aeb_Response__create();

/// Destroy srv/Aeb message.
/**
 * It calls
 * f1tenth_msgs__srv__Aeb_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Response__destroy(f1tenth_msgs__srv__Aeb_Response * msg);

/// Check for srv/Aeb message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Response__are_equal(const f1tenth_msgs__srv__Aeb_Response * lhs, const f1tenth_msgs__srv__Aeb_Response * rhs);

/// Copy a srv/Aeb message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Response__copy(
  const f1tenth_msgs__srv__Aeb_Response * input,
  f1tenth_msgs__srv__Aeb_Response * output);

/// Initialize array of srv/Aeb messages.
/**
 * It allocates the memory for the number of elements and calls
 * f1tenth_msgs__srv__Aeb_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Response__Sequence__init(f1tenth_msgs__srv__Aeb_Response__Sequence * array, size_t size);

/// Finalize array of srv/Aeb messages.
/**
 * It calls
 * f1tenth_msgs__srv__Aeb_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Response__Sequence__fini(f1tenth_msgs__srv__Aeb_Response__Sequence * array);

/// Create array of srv/Aeb messages.
/**
 * It allocates the memory for the array and calls
 * f1tenth_msgs__srv__Aeb_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
f1tenth_msgs__srv__Aeb_Response__Sequence *
f1tenth_msgs__srv__Aeb_Response__Sequence__create(size_t size);

/// Destroy array of srv/Aeb messages.
/**
 * It calls
 * f1tenth_msgs__srv__Aeb_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
void
f1tenth_msgs__srv__Aeb_Response__Sequence__destroy(f1tenth_msgs__srv__Aeb_Response__Sequence * array);

/// Check for srv/Aeb message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Response__Sequence__are_equal(const f1tenth_msgs__srv__Aeb_Response__Sequence * lhs, const f1tenth_msgs__srv__Aeb_Response__Sequence * rhs);

/// Copy an array of srv/Aeb messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_f1tenth_msgs
bool
f1tenth_msgs__srv__Aeb_Response__Sequence__copy(
  const f1tenth_msgs__srv__Aeb_Response__Sequence * input,
  f1tenth_msgs__srv__Aeb_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // F1TENTH_MSGS__SRV__DETAIL__AEB__FUNCTIONS_H_
