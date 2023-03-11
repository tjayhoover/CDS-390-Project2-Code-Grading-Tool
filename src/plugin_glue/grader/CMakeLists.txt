cmake_minimum_required(VERSION 3.5.0)
project(grader_adapter VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR/src/interfaces}")
target_link_libraries(${PROJECT_NAME} grader)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)