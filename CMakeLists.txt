cmake_minimum_required(VERSION 3.0.0)
project(BeetCode VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(Boost 1.81.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(BeetCode main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
