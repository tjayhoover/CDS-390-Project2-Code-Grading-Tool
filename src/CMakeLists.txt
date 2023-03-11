cmake_minimum_required(VERSION 3.5.0)
project(BeetCode VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

#Entry point to our program
add_executable(${PROJECT_NAME} main.cpp)

#Add subdirectories
add_subdirectory(submit_assignment/submit_assignment)

#Link some required libraries
find_package(Boost COMPONENTS date_time chrono REQUIRED)
if(Boost_FOUND)
  target_link_libraries(${PROJECT_NAME} Boost::date_time Boost::chrono)
endif()

target_link_libraries(${PROJECT_NAME} python_grader)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)