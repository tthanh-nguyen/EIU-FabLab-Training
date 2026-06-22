// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from f1tenth_msgs:srv/Aeb.idl
// generated code does not contain a copyright notice
#include "f1tenth_msgs/srv/detail/aeb__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
f1tenth_msgs__srv__Aeb_Request__init(f1tenth_msgs__srv__Aeb_Request * msg)
{
  if (!msg) {
    return false;
  }
  // desired_distance
  // ttc
  return true;
}

void
f1tenth_msgs__srv__Aeb_Request__fini(f1tenth_msgs__srv__Aeb_Request * msg)
{
  if (!msg) {
    return;
  }
  // desired_distance
  // ttc
}

bool
f1tenth_msgs__srv__Aeb_Request__are_equal(const f1tenth_msgs__srv__Aeb_Request * lhs, const f1tenth_msgs__srv__Aeb_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // desired_distance
  if (lhs->desired_distance != rhs->desired_distance) {
    return false;
  }
  // ttc
  if (lhs->ttc != rhs->ttc) {
    return false;
  }
  return true;
}

bool
f1tenth_msgs__srv__Aeb_Request__copy(
  const f1tenth_msgs__srv__Aeb_Request * input,
  f1tenth_msgs__srv__Aeb_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // desired_distance
  output->desired_distance = input->desired_distance;
  // ttc
  output->ttc = input->ttc;
  return true;
}

f1tenth_msgs__srv__Aeb_Request *
f1tenth_msgs__srv__Aeb_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  f1tenth_msgs__srv__Aeb_Request * msg = (f1tenth_msgs__srv__Aeb_Request *)allocator.allocate(sizeof(f1tenth_msgs__srv__Aeb_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(f1tenth_msgs__srv__Aeb_Request));
  bool success = f1tenth_msgs__srv__Aeb_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
f1tenth_msgs__srv__Aeb_Request__destroy(f1tenth_msgs__srv__Aeb_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    f1tenth_msgs__srv__Aeb_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
f1tenth_msgs__srv__Aeb_Request__Sequence__init(f1tenth_msgs__srv__Aeb_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  f1tenth_msgs__srv__Aeb_Request * data = NULL;

  if (size) {
    data = (f1tenth_msgs__srv__Aeb_Request *)allocator.zero_allocate(size, sizeof(f1tenth_msgs__srv__Aeb_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = f1tenth_msgs__srv__Aeb_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        f1tenth_msgs__srv__Aeb_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
f1tenth_msgs__srv__Aeb_Request__Sequence__fini(f1tenth_msgs__srv__Aeb_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      f1tenth_msgs__srv__Aeb_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

f1tenth_msgs__srv__Aeb_Request__Sequence *
f1tenth_msgs__srv__Aeb_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  f1tenth_msgs__srv__Aeb_Request__Sequence * array = (f1tenth_msgs__srv__Aeb_Request__Sequence *)allocator.allocate(sizeof(f1tenth_msgs__srv__Aeb_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = f1tenth_msgs__srv__Aeb_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
f1tenth_msgs__srv__Aeb_Request__Sequence__destroy(f1tenth_msgs__srv__Aeb_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    f1tenth_msgs__srv__Aeb_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
f1tenth_msgs__srv__Aeb_Request__Sequence__are_equal(const f1tenth_msgs__srv__Aeb_Request__Sequence * lhs, const f1tenth_msgs__srv__Aeb_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!f1tenth_msgs__srv__Aeb_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
f1tenth_msgs__srv__Aeb_Request__Sequence__copy(
  const f1tenth_msgs__srv__Aeb_Request__Sequence * input,
  f1tenth_msgs__srv__Aeb_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(f1tenth_msgs__srv__Aeb_Request);
    f1tenth_msgs__srv__Aeb_Request * data =
      (f1tenth_msgs__srv__Aeb_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!f1tenth_msgs__srv__Aeb_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          f1tenth_msgs__srv__Aeb_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!f1tenth_msgs__srv__Aeb_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "rosidl_runtime_c/string_functions.h"

bool
f1tenth_msgs__srv__Aeb_Response__init(f1tenth_msgs__srv__Aeb_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    f1tenth_msgs__srv__Aeb_Response__fini(msg);
    return false;
  }
  return true;
}

void
f1tenth_msgs__srv__Aeb_Response__fini(f1tenth_msgs__srv__Aeb_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
f1tenth_msgs__srv__Aeb_Response__are_equal(const f1tenth_msgs__srv__Aeb_Response * lhs, const f1tenth_msgs__srv__Aeb_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
f1tenth_msgs__srv__Aeb_Response__copy(
  const f1tenth_msgs__srv__Aeb_Response * input,
  f1tenth_msgs__srv__Aeb_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

f1tenth_msgs__srv__Aeb_Response *
f1tenth_msgs__srv__Aeb_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  f1tenth_msgs__srv__Aeb_Response * msg = (f1tenth_msgs__srv__Aeb_Response *)allocator.allocate(sizeof(f1tenth_msgs__srv__Aeb_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(f1tenth_msgs__srv__Aeb_Response));
  bool success = f1tenth_msgs__srv__Aeb_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
f1tenth_msgs__srv__Aeb_Response__destroy(f1tenth_msgs__srv__Aeb_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    f1tenth_msgs__srv__Aeb_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
f1tenth_msgs__srv__Aeb_Response__Sequence__init(f1tenth_msgs__srv__Aeb_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  f1tenth_msgs__srv__Aeb_Response * data = NULL;

  if (size) {
    data = (f1tenth_msgs__srv__Aeb_Response *)allocator.zero_allocate(size, sizeof(f1tenth_msgs__srv__Aeb_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = f1tenth_msgs__srv__Aeb_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        f1tenth_msgs__srv__Aeb_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
f1tenth_msgs__srv__Aeb_Response__Sequence__fini(f1tenth_msgs__srv__Aeb_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      f1tenth_msgs__srv__Aeb_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

f1tenth_msgs__srv__Aeb_Response__Sequence *
f1tenth_msgs__srv__Aeb_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  f1tenth_msgs__srv__Aeb_Response__Sequence * array = (f1tenth_msgs__srv__Aeb_Response__Sequence *)allocator.allocate(sizeof(f1tenth_msgs__srv__Aeb_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = f1tenth_msgs__srv__Aeb_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
f1tenth_msgs__srv__Aeb_Response__Sequence__destroy(f1tenth_msgs__srv__Aeb_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    f1tenth_msgs__srv__Aeb_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
f1tenth_msgs__srv__Aeb_Response__Sequence__are_equal(const f1tenth_msgs__srv__Aeb_Response__Sequence * lhs, const f1tenth_msgs__srv__Aeb_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!f1tenth_msgs__srv__Aeb_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
f1tenth_msgs__srv__Aeb_Response__Sequence__copy(
  const f1tenth_msgs__srv__Aeb_Response__Sequence * input,
  f1tenth_msgs__srv__Aeb_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(f1tenth_msgs__srv__Aeb_Response);
    f1tenth_msgs__srv__Aeb_Response * data =
      (f1tenth_msgs__srv__Aeb_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!f1tenth_msgs__srv__Aeb_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          f1tenth_msgs__srv__Aeb_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!f1tenth_msgs__srv__Aeb_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
