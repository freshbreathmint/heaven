# Project Settings
cmake_minimum_required(VERSION 3.25)
project(heaven)

# Configure GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# Build Subdirectories
add_subdirectory(thirdparty/glad)       # GLAD & KHR
add_subdirectory(thirdparty/glfw)       # GLFW
add_subdirectory(thirdparty/stb_image)  # STB Image

# Include
include_directories(include)

# Set Sources
set(SOURCES
    src/main.c
    src/object.c
    src/readfile.c
    src/render.c
    src/shader.c
    src/texture.c
)

# Add Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Libraries
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE 
    glfw
    glad
    stb_image
)

# Copy resources/ to build/ using a custom command
add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)

# Make sure that the "copy_resources" target is built before your main executable
add_dependencies(${PROJECT_NAME} copy_resources)