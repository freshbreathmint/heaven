#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// Key Callback
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, 1);
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
    Shader_init(&shader, "resources/vertexShader.glsl", "resources/fragmentShader.glsl");

    // Vertex Data
    float verticies[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Generate  & Configure Array/Buffers
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    // Link Vertex Attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Set Clear Buffer Color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear Buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Use Shader
        Shader_use(&shader);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap Buffers, Poll Events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Exit Gracefully.
    glfwTerminate();
    return 0;
}