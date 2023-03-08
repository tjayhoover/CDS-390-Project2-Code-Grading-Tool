cmake_minimum_required(VERSION 3.0.0)
project(BeetCode VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(BeetCode main.cpp)

find_package(Boost COMPONENTS date_time chrono REQUIRED)
if(Boost_FOUND)
  target_link_libraries(${PROJECT_NAME} Boost::date_time Boost::chrono)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)