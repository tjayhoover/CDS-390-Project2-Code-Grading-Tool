cmake_minimum_required(VERSION 3.5.0)
project(grader_lib VERSION 0.1.0)

#Tell compiler where to look for the interface headers - is this ok?
message("${CMAKE_SOURCE_DIR}/src/interfaces")

set(CMAKE_CXX_STANDARD 17)

add_library(grader  src/grader.cpp include/grader.hpp)

target_include_directories(grader PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/src/interfaces")

#This is so cool wtf is it even doing
target_include_directories(grader INTERFACE "${CMAKE_SOURCE_DIR}/src/interfaces")