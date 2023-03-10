cmake_minimum_required(VERSION 3.5.0)
project(GraderTests)

enable_testing()

add_executable(${PROJECT_NAME} grader_tests.cpp)

find_package(GTest CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    GTest::gtest
    GTest::gtest_main
    grader
)

#Tell compiler where to look for the interface headers - I think this is very bad
include_directories(/home/tjayhoover/project-2-beetcode-v0-2/src/interfaces)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

include(GoogleTest)