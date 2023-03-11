cmake_minimum_required(VERSION 3.5.0)
project(submit_assignment VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

#Expose the abstract interfaces to the use case - I don't want to use this though
include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src/interfaces")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)