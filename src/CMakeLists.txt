cmake_minimum_required(VERSION 3.5.0)
project(BeetCode VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

#Tell compiler where to look for the interface headers
include_directories(${PROJECT_SOURCE_DIR}/interfaces)

#Link to plugins subdirectory
add_subdirectory(plugins/grader)

#Entry point to our program
add_executable(BeetCode main.cpp)

#Include external libraries
find_package(Boost COMPONENTS date_time chrono REQUIRED)
if(Boost_FOUND)
  target_link_libraries(${PROJECT_NAME} Boost::date_time Boost::chrono)
endif()

#Include internal libraries
target_link_libraries(${PROJECT_NAME} grader)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)