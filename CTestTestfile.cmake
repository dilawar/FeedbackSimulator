# CMake generated Testfile for 
# Source directory: /home/dilawar/Work/GITHUB/FeedbackSimulator
# Build directory: /home/dilawar/Work/GITHUB/FeedbackSimulator
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(load_module_test "/usr/bin/python" "test.py")
SET_TESTS_PROPERTIES(load_module_test PROPERTIES  WORKING_DIRECTORY "tests")
SUBDIRS(src)
