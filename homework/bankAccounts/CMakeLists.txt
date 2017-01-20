cmake_minimum_required(VERSION 3.6)
project(problem_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp date.cpp date.h money.cpp money.h accountHolder.cpp accountHolder.h bankAccount.cpp bankAccount.h)
add_executable(problem_1 ${SOURCE_FILES})