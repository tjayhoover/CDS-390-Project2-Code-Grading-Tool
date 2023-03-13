cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

target_sources(${PROJECT_NAME} PRIVATE submit_assignment.cpp submit_assignment.hpp)

#Expose the abstract interfaces to the use case - I don't want to use this though
include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src/interfaces")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)