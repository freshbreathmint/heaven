cmake_minimum_required(VERSION 3.25)
project(heaven)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glfw)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE 
    glfw
    glad
    )