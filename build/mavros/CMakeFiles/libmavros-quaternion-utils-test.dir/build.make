# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/safmc/catkin_ws/src/mavros/mavros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/safmc/catkin_ws/build/mavros

# Include any dependencies generated for this target.
include CMakeFiles/libmavros-quaternion-utils-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libmavros-quaternion-utils-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libmavros-quaternion-utils-test.dir/flags.make

CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o: CMakeFiles/libmavros-quaternion-utils-test.dir/flags.make
CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o: /home/safmc/catkin_ws/src/mavros/mavros/test/test_quaternion_utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safmc/catkin_ws/build/mavros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o -c /home/safmc/catkin_ws/src/mavros/mavros/test/test_quaternion_utils.cpp

CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safmc/catkin_ws/src/mavros/mavros/test/test_quaternion_utils.cpp > CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.i

CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safmc/catkin_ws/src/mavros/mavros/test/test_quaternion_utils.cpp -o CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.s

CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.requires:

.PHONY : CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.requires

CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.provides: CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/libmavros-quaternion-utils-test.dir/build.make CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.provides.build
.PHONY : CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.provides

CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.provides.build: CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o


# Object files for target libmavros-quaternion-utils-test
libmavros__quaternion__utils__test_OBJECTS = \
"CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o"

# External object files for target libmavros-quaternion-utils-test
libmavros__quaternion__utils__test_EXTERNAL_OBJECTS =

/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: CMakeFiles/libmavros-quaternion-utils-test.dir/build.make
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: gtest/googlemock/gtest/libgtest.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /home/safmc/catkin_ws/devel/.private/mavros/lib/libmavros.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libdiagnostic_updater.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libeigen_conversions.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/liborocos-kdl.so.1.4.0
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /home/safmc/catkin_ws/devel/.private/libmavconn/lib/libmavconn.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libclass_loader.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/libPocoFoundation.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libdl.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libroslib.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/librospack.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libpython2.7.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_program_options.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libtinyxml2.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/librosconsole_bridge.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libtf2_ros.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libactionlib.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libmessage_filters.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libroscpp.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_filesystem.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/librosconsole.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/liblog4cxx.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_regex.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libtf2.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/librostime.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /opt/ros/melodic/lib/libcpp_common.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_system.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_thread.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_chrono.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_date_time.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_atomic.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libpthread.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_system.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_thread.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_chrono.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_date_time.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libboost_atomic.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libpthread.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: /usr/lib/aarch64-linux-gnu/libGeographic.so
/home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test: CMakeFiles/libmavros-quaternion-utils-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/safmc/catkin_ws/build/mavros/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libmavros-quaternion-utils-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libmavros-quaternion-utils-test.dir/build: /home/safmc/catkin_ws/devel/.private/mavros/lib/mavros/libmavros-quaternion-utils-test

.PHONY : CMakeFiles/libmavros-quaternion-utils-test.dir/build

CMakeFiles/libmavros-quaternion-utils-test.dir/requires: CMakeFiles/libmavros-quaternion-utils-test.dir/test/test_quaternion_utils.cpp.o.requires

.PHONY : CMakeFiles/libmavros-quaternion-utils-test.dir/requires

CMakeFiles/libmavros-quaternion-utils-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libmavros-quaternion-utils-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libmavros-quaternion-utils-test.dir/clean

CMakeFiles/libmavros-quaternion-utils-test.dir/depend:
	cd /home/safmc/catkin_ws/build/mavros && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/safmc/catkin_ws/src/mavros/mavros /home/safmc/catkin_ws/src/mavros/mavros /home/safmc/catkin_ws/build/mavros /home/safmc/catkin_ws/build/mavros /home/safmc/catkin_ws/build/mavros/CMakeFiles/libmavros-quaternion-utils-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libmavros-quaternion-utils-test.dir/depend

