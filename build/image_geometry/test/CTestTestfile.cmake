# CMake generated Testfile for 
# Source directory: /home/safmc/catkin_ws/src/vision_opencv/image_geometry/test
# Build directory: /home/safmc/catkin_ws/build/image_geometry/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_image_geometry_nosetests_directed.py "/home/safmc/catkin_ws/build/image_geometry/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/safmc/catkin_ws/build/image_geometry/test_results/image_geometry/nosetests-directed.py.xml" "--return-code" "\"/usr/bin/cmake\" -E make_directory /home/safmc/catkin_ws/build/image_geometry/test_results/image_geometry" "/usr/bin/nosetests-2.7 -P --process-timeout=60 /home/safmc/catkin_ws/src/vision_opencv/image_geometry/test/directed.py --with-xunit --xunit-file=/home/safmc/catkin_ws/build/image_geometry/test_results/image_geometry/nosetests-directed.py.xml")
add_test(_ctest_image_geometry_gtest_image_geometry-utest "/home/safmc/catkin_ws/build/image_geometry/catkin_generated/env_cached.sh" "/usr/bin/python2" "/opt/ros/melodic/share/catkin/cmake/test/run_tests.py" "/home/safmc/catkin_ws/build/image_geometry/test_results/image_geometry/gtest-image_geometry-utest.xml" "--return-code" "/home/safmc/catkin_ws/devel/.private/image_geometry/lib/image_geometry/image_geometry-utest --gtest_output=xml:/home/safmc/catkin_ws/build/image_geometry/test_results/image_geometry/gtest-image_geometry-utest.xml")
