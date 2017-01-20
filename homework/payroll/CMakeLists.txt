cmake_minimum_required(VERSION 3.6)
project(payroll)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp functions.cpp utilities.h objects.h)
add_executable(payroll ${SOURCE_FILES})