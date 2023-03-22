cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

target_sources(${PROJECT_NAME} PRIVATE student_report.cpp)

#Expose the abstract interfaces to the use case - I don't want to use this though
include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src/interfaces")