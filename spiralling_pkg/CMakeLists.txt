cmake_minimum_required(VERSION 3.8)
project(spiralling_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#just about the dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(spiralling_node src/spiralling_node.cpp)
ament_target_dependencies(spiralling_node rclcpp geometry_msgs)

# done about the dependenices


target_include_directories(spiralling_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(spiralling_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS spiralling_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
