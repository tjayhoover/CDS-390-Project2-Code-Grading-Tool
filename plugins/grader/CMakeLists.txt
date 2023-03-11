cmake_minimum_required(VERSION 3.5.0)
project(grader VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME}  src/grader.cpp include/grader.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" PRIVATE "${CMAKE_SOURCE_DIR}/src/interfaces")

#This is so cool wtf is it even doing
target_include_directories(${PROJECT_NAME} INTERFACE "${CMAKE_SOURCE_DIR}/src/interfaces")