cmake_minimum_required(VERSION 3.13.0)
project(authentication VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} src/authentication.cpp include/authentication.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")