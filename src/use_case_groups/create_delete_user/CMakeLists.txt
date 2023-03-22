cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(controllers)

# Add the create user use case
add_subdirectory(interactors/create_user)
add_subdirectory(views/create_user)
add_subdirectory(presenters/create_user)

# Add the delete user use case
add_subdirectory(interactors/delete_user)
add_subdirectory(views/delete_user)
add_subdirectory(presenters/delete_user)