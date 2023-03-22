cmake_minimum_required(VERSION 3.13.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(database)
add_subdirectory(python_grader)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)