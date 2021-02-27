cmake_minimum_required(VERSION 3.0.2)
project(openmv_test)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  roscpp
  sensor_msgs
  std_msgs
  geometry_msgs
  roslaunch
)

find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES zed_window_sub
#  CATKIN_DEPENDS cv_bridge roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########


include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

link_directories(${OpenCV_LIB_DIR})



add_executable(capture src/capture.cpp)
target_link_libraries(capture
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)



add_executable(openmv_test src/openmv_test.cpp)
target_link_libraries(openmv_test 
  ${catkin_LIBRARIES} 
  ${OpenCV_LIBRARIES})



if (CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)
  roslaunch_add_file_check(launch)
endif()


