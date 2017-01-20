cmake_minimum_required(VERSION 3.6)
project(inheritance)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Money.cpp Money.h Employee.cpp Employee.h CanadianMoney.cpp CanadianMoney.h USMoney.cpp USMoney.h utilities.cpp utilities.h)
add_executable(inheritance ${SOURCE_FILES})