cmake_minimum_required(VERSION 3.13.0)
project(BeetCode VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(src)
add_subdirectory(plugins)
add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)