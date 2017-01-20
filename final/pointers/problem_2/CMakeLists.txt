cmake_minimum_required(VERSION 3.6)
project(problem_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp functions.cpp utilities.h)
add_executable(problem_3 ${SOURCE_FILES})