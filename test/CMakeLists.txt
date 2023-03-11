cmake_minimum_required(VERSION 3.5.0)
project(GraderTests)

enable_testing()

add_executable(${PROJECT_NAME} grader_tests.cpp)

find_package(GTest CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    GTest::gtest
    GTest::gtest_main
    python_grader
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)

include(GoogleTest)