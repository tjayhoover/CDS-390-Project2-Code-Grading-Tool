cmake_minimum_required(VERSION 3.13.0)
project(python_grader VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} src/python_grader.cpp include/python_grader.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")