cmake_minimum_required(VERSION 3.13.0)

set(CMAKE_CXX_STANDARD 17)

target_sources(${PROJECT_NAME} PRIVATE grader.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)