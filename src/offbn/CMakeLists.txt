cmake_minimum_required(VERSION 3.0.2)
project(offbn)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  mavros_msgs
  roscpp
  rospy
  std_msgs
)


catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

#add_executable(${PROJECT_NAME}_node src/offbn_node.cpp)
add_executable(${PROJECT_NAME}_land src/outdoor_land.cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(${PROJECT_NAME}_land
   ${catkin_LIBRARIES}
 )

 #add_executable(${PROJECT_NAME}_node src/offbn_node.cpp)
add_executable(${PROJECT_NAME}_420 src/outdoor_4m_20m.cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(${PROJECT_NAME}_420
   ${catkin_LIBRARIES}
 )

#add_executable(${PROJECT_NAME}_node src/offbn_node.cpp)
add_executable(${PROJECT_NAME}_620 src/outdoor_6m_20m.cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(${PROJECT_NAME}_620
   ${catkin_LIBRARIES}
 )

#add_executable(${PROJECT_NAME}_node src/offbn_node.cpp)
add_executable(${PROJECT_NAME}_4hover src/outdoor_4m_hover.cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(${PROJECT_NAME}_4hover
   ${catkin_LIBRARIES}
 )

 #add_executable(${PROJECT_NAME}_node src/offbn_node.cpp)
add_executable(${PROJECT_NAME}_6hover src/outdoor_6m_hover.cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(${PROJECT_NAME}_6hover
   ${catkin_LIBRARIES}
 )
