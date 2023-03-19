cmake_minimum_required(VERSION 3.13.0)
project(BeetCode VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

#Entry point to our program
add_executable(${PROJECT_NAME} main.cpp)

#Link some required libraries
find_package(Boost COMPONENTS date_time chrono REQUIRED)
if(Boost_FOUND)
  target_link_libraries(${PROJECT_NAME} PUBLIC Boost::date_time Boost::chrono)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC python_grader)

#Are these both required?
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/src/interfaces")
#target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/src/entities")

#Add subdirectories
add_subdirectory(entities)
add_subdirectory(submit_assignment/submit_assignment)
add_subdirectory(plugin_glue/grader)
add_subdirectory(plugin_glue/database)
add_subdirectory(plugin_glue/authenticator)


#The following two lines print all the source files compiled by the target
#get_target_property(v BeetCode SOURCES)
#message(${v})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)