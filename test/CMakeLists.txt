cmake_minimum_required(VERSION 3.13.0)
project(GraderTests)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(${PROJECT_NAME}
    user_test.cpp
    grader_tests.cpp
    other_tests.cpp
    authentication_test.cpp
    ../src/entities/user/user.cpp
   )

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