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
CMAKE_SOURCE_DIR = /home/safmc/catkin_ws/src/teraranger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/safmc/catkin_ws/build/teraranger

# Include any dependencies generated for this target.
include CMakeFiles/duo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/duo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/duo.dir/flags.make

CMakeFiles/duo.dir/src/teraranger_duo.cpp.o: CMakeFiles/duo.dir/flags.make
CMakeFiles/duo.dir/src/teraranger_duo.cpp.o: /home/safmc/catkin_ws/src/teraranger/src/teraranger_duo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safmc/catkin_ws/build/teraranger/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/duo.dir/src/teraranger_duo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/duo.dir/src/teraranger_duo.cpp.o -c /home/safmc/catkin_ws/src/teraranger/src/teraranger_duo.cpp

CMakeFiles/duo.dir/src/teraranger_duo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/duo.dir/src/teraranger_duo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safmc/catkin_ws/src/teraranger/src/teraranger_duo.cpp > CMakeFiles/duo.dir/src/teraranger_duo.cpp.i

CMakeFiles/duo.dir/src/teraranger_duo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/duo.dir/src/teraranger_duo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safmc/catkin_ws/src/teraranger/src/teraranger_duo.cpp -o CMakeFiles/duo.dir/src/teraranger_duo.cpp.s

CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.requires:

.PHONY : CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.requires

CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.provides: CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.requires
	$(MAKE) -f CMakeFiles/duo.dir/build.make CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.provides.build
.PHONY : CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.provides

CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.provides.build: CMakeFiles/duo.dir/src/teraranger_duo.cpp.o


CMakeFiles/duo.dir/src/helper_lib.cpp.o: CMakeFiles/duo.dir/flags.make
CMakeFiles/duo.dir/src/helper_lib.cpp.o: /home/safmc/catkin_ws/src/teraranger/src/helper_lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/safmc/catkin_ws/build/teraranger/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/duo.dir/src/helper_lib.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/duo.dir/src/helper_lib.cpp.o -c /home/safmc/catkin_ws/src/teraranger/src/helper_lib.cpp

CMakeFiles/duo.dir/src/helper_lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/duo.dir/src/helper_lib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/safmc/catkin_ws/src/teraranger/src/helper_lib.cpp > CMakeFiles/duo.dir/src/helper_lib.cpp.i

CMakeFiles/duo.dir/src/helper_lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/duo.dir/src/helper_lib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/safmc/catkin_ws/src/teraranger/src/helper_lib.cpp -o CMakeFiles/duo.dir/src/helper_lib.cpp.s

CMakeFiles/duo.dir/src/helper_lib.cpp.o.requires:

.PHONY : CMakeFiles/duo.dir/src/helper_lib.cpp.o.requires

CMakeFiles/duo.dir/src/helper_lib.cpp.o.provides: CMakeFiles/duo.dir/src/helper_lib.cpp.o.requires
	$(MAKE) -f CMakeFiles/duo.dir/build.make CMakeFiles/duo.dir/src/helper_lib.cpp.o.provides.build
.PHONY : CMakeFiles/duo.dir/src/helper_lib.cpp.o.provides

CMakeFiles/duo.dir/src/helper_lib.cpp.o.provides.build: CMakeFiles/duo.dir/src/helper_lib.cpp.o


# Object files for target duo
duo_OBJECTS = \
"CMakeFiles/duo.dir/src/teraranger_duo.cpp.o" \
"CMakeFiles/duo.dir/src/helper_lib.cpp.o"

# External object files for target duo
duo_EXTERNAL_OBJECTS =

/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: CMakeFiles/duo.dir/src/teraranger_duo.cpp.o
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: CMakeFiles/duo.dir/src/helper_lib.cpp.o
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: CMakeFiles/duo.dir/build.make
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/libroscpp.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_filesystem.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/librosconsole.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/liblog4cxx.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_regex.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/libdynamic_reconfigure_config_init_mutex.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/libserial.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/librostime.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /opt/ros/melodic/lib/libcpp_common.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_system.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_thread.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_chrono.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_date_time.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_atomic.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libpthread.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_system.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_thread.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_chrono.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_date_time.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libboost_atomic.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libpthread.so
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: /usr/lib/aarch64-linux-gnu/libconsole_bridge.so.0.4
/home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo: CMakeFiles/duo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/safmc/catkin_ws/build/teraranger/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/duo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/duo.dir/build: /home/safmc/catkin_ws/devel/.private/teraranger/lib/teraranger/duo

.PHONY : CMakeFiles/duo.dir/build

CMakeFiles/duo.dir/requires: CMakeFiles/duo.dir/src/teraranger_duo.cpp.o.requires
CMakeFiles/duo.dir/requires: CMakeFiles/duo.dir/src/helper_lib.cpp.o.requires

.PHONY : CMakeFiles/duo.dir/requires

CMakeFiles/duo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/duo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/duo.dir/clean

CMakeFiles/duo.dir/depend:
	cd /home/safmc/catkin_ws/build/teraranger && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/safmc/catkin_ws/src/teraranger /home/safmc/catkin_ws/src/teraranger /home/safmc/catkin_ws/build/teraranger /home/safmc/catkin_ws/build/teraranger /home/safmc/catkin_ws/build/teraranger/CMakeFiles/duo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/duo.dir/depend

