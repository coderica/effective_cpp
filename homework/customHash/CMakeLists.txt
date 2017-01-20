cmake_minimum_required(VERSION 3.6)
project(customHash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp KeyValuePair.cpp KeyValuePair.h PairList.cpp PairList.h utilities.cpp utilities.h)
add_executable(customHash ${SOURCE_FILES})