cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(controllers)

# Add the create assignment use case
add_subdirectory(interactors/create_assignment)
add_subdirectory(views/create_assignment)
add_subdirectory(presenters/create_assignment)

# Add the delete assignment use case
add_subdirectory(interactors/delete_assignment)
add_subdirectory(views/delete_assignment)
add_subdirectory(presenters/delete_assignment)