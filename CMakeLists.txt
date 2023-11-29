# Project Settings
cmake_minimum_required(VERSION 3.25)
project(heaven)

# Configure GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# Build Subdirectories
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glfw)

# Include
include_directories(include)

# Set Sources
set(SOURCES
    src/main.c
    src/object.c
    src/readfile.c
    src/render.c
    src/shader.c
)

# Add Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Libraries
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE 
    glfw
    glad
)

# Copy resources/ to build/
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})