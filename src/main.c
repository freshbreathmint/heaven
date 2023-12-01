#include <math.h>
#include <stdio.h>

#include <cglm/cglm.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "object.h"
#include "render.h"
#include "shader.h"
#include "texture.h"

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

static _Bool wireframeMode = 0; // 0 = FILL, 1 = WIREFRAME

// Key Callback
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, 1);
    
    if (key == GLFW_KEY_X && action == GLFW_PRESS)
    {
        wireframeMode = !wireframeMode;
        if (wireframeMode)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

// Framebuffer Size Callback
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // Resize viewport when window is resized.
    glViewport(0, 0, width, height);
}

// Main
int main() 
{
    // Initalize and Configure GLFW - (Version 4.6, Core Profile)
    if (!glfwInit()) {
        printf("Failed to initalize GLFW.\n");
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create and Configure Window Object
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "heaven", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create window.\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Set Callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, keyCallback);

    // Initalize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initalize GLAD.\n");
        return 1;
    }

    // Build Shaders
    Shader shader;
    Shader_init(&shader, "resources/shader/vertexShader-Transform.glsl", "resources/shader/fragmentShader-Mix.glsl");

    // Create Objects
    Object object;
    createObject(&object, "resources/geometry/quad.txt");

    // Load Textures
    unsigned int texture = loadTexture("resources/texture/container.jpg", GL_RGB, GL_RGB);
    unsigned int texture2 = loadTexture("resources/texture/awesomeface.png", GL_RGBA, GL_RGBA);
    Shader_use(&shader);
    Shader_setInt(&shader, "textureInput", 0);
    Shader_setInt(&shader, "textureInput2", 1);

    // Set Clear Buffer Color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear Buffer
        glClear(GL_COLOR_BUFFER_BIT);


        /* Vector Playground */
        mat4 trans; // Create an empty matrix
        glm_mat4_identity(trans); // Initalize as identity matrix which looks like this:
        
        /*
        1 0 0 0
        0 1 0 0
        0 0 1 0
        0 0 0 1
        */

        float angle = 0.0f;
        //float angle = (float)glfwGetTime();
        vec3 axis = {0.0f, 0.0f, 1.0f};
        vec3 scale = {0.5f, 0.5f, 0.5f};

        glm_rotate(trans, angle, axis);
        
        

        Shader_setMatrix4fv(&shader, "transform", 1, GL_FALSE, trans);
        /* Figure out how this shit works before you continue */

        // Bind Texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        // Render Object(s)
        renderObject(&shader, &object);

        // Swap Buffers, Poll Events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Exit Gracefully.
    glfwTerminate();
    return 0;
}