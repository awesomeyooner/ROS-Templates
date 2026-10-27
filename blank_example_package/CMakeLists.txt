cmake_minimum_required(VERSION 3.16)
project(example_package LANGUAGES C CXX) # CHANGE ME

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# In order to compile external libs
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Dependency list
set(THIS_PACKAGE_INCLUDE_DEPENDS
  ament_cmake
  backward_ros
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  generate_parameter_library
  CURL
)

# Find all dependencies
foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

# Bringup (yaml configs, launch files)
install(
  DIRECTORY bringup/launch bringup/config
  DESTINATION share/${PROJECT_NAME}
)

# Export for AMENT
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()