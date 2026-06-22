cmake_minimum_required(VERSION 3.8)
project(ros2_basic)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)

install(PROGRAMS
  ros2_basic/simple_node.py
  ros2_basic/publisher_node.py
  ros2_basic/subscriber_node.py
  ros2_basic/drive.py
  ros2_basic/odom.py
  ros2_basic/control_meter.py
  ros2_basic/scan_node.py
  ros2_basic/detectObstacle.py
  ros2_basic/detectObstacle1.py
  ros2_basic/simple_server.py
  ros2_basic/simple_clients.py
  ros2_basic/1_clients_detectObstacle.py
  ros2_basic/1_server_detectObstacle.py
  ros2_basic/PID.py
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
