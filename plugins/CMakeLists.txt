cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(database)
add_subdirectory(python_grader)
#add_subdirectory(UI)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)