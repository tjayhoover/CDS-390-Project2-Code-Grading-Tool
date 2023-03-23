cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(controllers)

# Add the student view use case
add_subdirectory(interactors/student)
add_subdirectory(views/student)
add_subdirectory(presenters/student)

