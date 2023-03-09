cmake_minimum_required(VERSION 3.2.0)
project(grader_lib VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES include/grader.hpp src/grader.cpp)

add_library(grader SHARED STATIC ${SOURCE_FILES})

target_include_directories(grader PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")