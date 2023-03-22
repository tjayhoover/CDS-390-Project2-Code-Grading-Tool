cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(controllers)

# Add the instructor grade report use case
add_subdirectory(interactors/instructor)
add_subdirectory(views/instructor)
add_subdirectory(presenters/instructor)

# Add the student grade report use case
add_subdirectory(interactors/student)
add_subdirectory(views/student)
add_subdirectory(presenters/student)