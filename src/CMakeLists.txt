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
target_link_libraries(${PROJECT_NAME} PUBLIC bauer_database)
target_link_libraries(${PROJECT_NAME} PUBLIC authentication)

#Are these both required?
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/src/interfaces")
#target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/src/entities")

#Add subdirectories
add_subdirectory(entities)


# Add the library adapters
add_subdirectory(adapters/grader)
add_subdirectory(adapters/database)
add_subdirectory(adapters/authenticator)

# Add the use case groups
add_subdirectory(use_case_groups/submit_assignment)
add_subdirectory(use_case_groups/log_in_out)
add_subdirectory(use_case_groups/create_delete_assignment)
add_subdirectory(use_case_groups/create_delete_user)
add_subdirectory(use_case_groups/grade_report)
add_subdirectory(use_case_groups/view_assignments)

# Add the user interface
add_subdirectory(console_interface)

#The following two lines print all the source files compiled by the target
#get_target_property(v BeetCode SOURCES)
#message(${v})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)