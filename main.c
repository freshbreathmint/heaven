#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
    GLFWwindow *window = glfwCreateWindow(800, 600, "heaven", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create window.\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Initalize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initalize GLAD.\n");
        return 1;
    }

    // Configure Viewport
    glViewport(0, 0, 800, 600);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Exit Gracefully.
    glfwTerminate();
    return 0;
}