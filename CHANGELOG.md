# Version History

## 0.0.16

Features:

    - Camera system

## 0.0.15

Features

    - Cleaned up shaders, we are just using verticies and texture coords now, no more color.
    - Added cube geometry
    - Updated default shaders
    - Updated old geometry to not use color
    - Rotating 3D cube wow

## 0.0.14

Features: 

    - Real ass 3D graphics
    - Projection, view, model matricies (not permanant solution probably)
    - Added mints.png for vanity
    - Shader_setMatrix4fv now only takes two arguments for brevity.

## 0.0.13

Features:

    - Add CGLM library
    - There's a second box, and the boxes are now rotating. Thrilling.

## 0.0.12

Features:

    - Added stb_image library
    - Added textures, we use texture coordinates in our geometry now. good stuff.
    - Removed exercises
    - Added different fragment shaders.
    - Added three new textures

## 0.0.11

Features:
    
    - Added new exercise shaders
    - CMake now properly copies resources to build every time.

## 0.0.10

Features:

    - Colored triangle.
    - Cleaned up old geometry and shader data, we are using colored vertex attributes now.
    - Changed setColor to setFloat4

## 0.0.9

Features:
    
    - Moved shaders into resources/shader/
    - New uniform functions for shaders
    - Added tri.txt to geometry
    - Custom color fragment shader
    - Flashing green triangle!!!

## 0.0.8

Features:

    - Geometry and Object structs are now the same, very clean.
    - Added rendering function.

## 0.0.7

Features:

    - Geometry can be read from a file now. The system is modular!!!


## 0.0.6

Features:

    - VAO, VBO, EBO, are now stored inside of an Object struct.

## 0.0.5

Features:

    - Holy shit two triangles!?
    - Added wireframe mode (Press X to Toggle)

## 0.0.4

Features:

    - Based Triangle???
    - Barebones shader system
    - Basic vertex and fragment shaders
    - File reading system

## 0.0.3

Features:

    - Default resolution now defined in const
    - Added Key Callback
        - Escape Key now closes the window
    - Added Framebuffer Size Callback
    - Loop now calls glClear()
        - Clear color is set to a default tutorial color

## 0.0.2

Features:

    - Add Glad and GLFW libraries
    - Program now opens a basic GLFW window

## 0.0.1

Features:

    - Add .gitignore
    - Add basic program
    - Add CMakeLists.txt
    - Add Toolchain-MinGW64.cmake which might not be neccesary

## 0.0.0

Note:

    - Began Project
    - Added Licence, Changelog, Readme