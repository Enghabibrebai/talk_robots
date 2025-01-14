cmake_minimum_required(VERSION 3.0.2)
project(ur5_simulation)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  moveit_core
  moveit_ros_planning
  moveit_ros_planning_interface
  geometry_msgs
  find_object_2d
  tf2_ros
  message_generation
)

find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)

add_message_files(
  FILES
  Tracker.msg
)
add_service_files(
  FILES
  GetPosition.srv
)
# Include directories
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

# Generate messages
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp moveit_core moveit_ros_planning moveit_ros_planning_interface geometry_msgs std_msgs find_object_2d tf2_ros message_runtime
)

# Create the tracker executable
add_executable(tracker src/tracker.cpp)
target_link_libraries(tracker
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)

# Create the pick_and_place executable
add_executable(object_tracking src/object_tracking.cpp)
target_link_libraries(object_tracking
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)
add_executable(pick_place_simple_client src/pick_place_simple_client.cpp)
add_dependencies(pick_place_simple_client ${cobot_test_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(pick_place_simple_client ${catkin_LIBRARIES})

add_executable(ur5_ik_test src/ur5_ik_test.cpp)
add_dependencies(ur5_ik_test ${cobot_test_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ur5_ik_test ${catkin_LIBRARIES})

add_executable(ur5_pick_place src/ur5_pick_place.cpp)
add_dependencies(ur5_pick_place ${cobot_test_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ur5_pick_place ${catkin_LIBRARIES})