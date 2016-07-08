cmake_minimum_required(VERSION 3.5)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 283.c 344.c 344.h main.c 258.c 258.h 349.c 349.h 237.c 237.h)
add_executable(leetcode ${SOURCE_FILES})