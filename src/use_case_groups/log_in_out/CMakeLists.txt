cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(controllers)

# Add the log in use case
add_subdirectory(interactors/log_in)
add_subdirectory(views/log_in)
add_subdirectory(presenters/log_in)

# Add the log out use case
add_subdirectory(interactors/log_out)
add_subdirectory(views/log_out)
add_subdirectory(presenters/log_out)