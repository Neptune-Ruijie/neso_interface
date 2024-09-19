cmake_minimum_required(VERSION 3.5)
project(naiad_interfaces)


set(RULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/rules)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include(${RULES_DIR}/ws_common.cmake)

## 自动添加文件
#file(GLOB MSG_FILES msg/*.msg)
file(GLOB MSG_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ msg/*.msg)
file(GLOB SRV_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ srv/*.srv)
file(GLOB ACTION_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ action/*.action)

message(STATUS "MSG_FILES=${MSG_FILES}")
message(STATUS "SRV_FILES=${SRV_FILES}")
message(STATUS "ACTION_FILES=${ACTION_FILES}")

## 可以在非ROS做一些测试
if(WS_ROS)

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(action_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)


rosidl_generate_interfaces(${PROJECT_NAME}
  ${MSG_FILES}
  ${SRV_FILES}
  ${ACTION_FILES}
  DEPENDENCIES builtin_interfaces std_msgs action_msgs geometry_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(
    DIRECTORY helper
    DESTINATION include/${PROJECT_NAME}
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()

endif()
