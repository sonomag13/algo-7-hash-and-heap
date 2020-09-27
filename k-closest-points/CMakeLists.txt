cmake_minimum_required(VERSION 3.17)

# set the project name
project(KClosestPoints)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(KClosestPoints main.cpp Solution.h Solution2.h DataStructure.h)