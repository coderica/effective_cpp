cmake_minimum_required(VERSION 3.6)
project(smart_data)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp SmartString.h SmartArray.h SmartString.cpp SmartArray.cpp)
add_executable(smart_data ${SOURCE_FILES})