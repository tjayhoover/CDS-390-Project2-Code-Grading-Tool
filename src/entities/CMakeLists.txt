cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

target_sources(${PROJECT_NAME} PRIVATE user/user.cpp submission/submission.cpp assignment/assignment.cpp) #assignment/assignment.cpp)