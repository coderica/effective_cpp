cmake_minimum_required(VERSION 3.6)
project(media_rental)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Member.h Item.h Blockbuster.h Movie.h Game.h Audiobook.h members.txt movies.txt games.txt audiobooks.txt)
add_executable(media_rental ${SOURCE_FILES})