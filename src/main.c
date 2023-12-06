#include <math.h>
#include <stdio.h>

#include <cglm/cglm.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.h"
#include "object.h"
#include "render.h"
#include "shader.h"
#include "texture.h"

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const float FOV = 45.0f;

static _Bool wireframeMode = 0; // 0 = FILL, 1 = WIREFRAME

Camera camera;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

// Key Callback
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    // Check Important Things
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
    {
        glfwSetWindowShouldClose(window, 1);
    }

    if (key == GLFW_KEY_X && action == GLFW_PRESS)
    {
        wireframeMode = !wireframeMode;
        if (wireframeMode)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
        //todo
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
        //todo
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
        //todo
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
        //todo
        
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
    
    // Enable Depth Testing
    glEnable(GL_DEPTH_TEST);

    // Build Shaders
    Shader shader;
    Shader_init(&shader, "resources/shader/vertexShader-Default.glsl", "resources/shader/fragmentShader-Default.glsl");

    // Create Objects
    Object object;
    createObject(&object, "resources/geometry/cube.txt");

    // Load Textures
    unsigned int texture = loadTexture("resources/texture/mints.png", GL_RGB, GL_RGB);
    Shader_use(&shader);
    Shader_setInt(&shader, "textureInput", 0);

    // Positions To Spawn
    vec3 objectPositions[] = {
        {0.0f, 0.0f, 0.0f},
        {2.0f, 5.0f, -15.0f},
        {-1.5f, -2.2f, -2.5f},
        {-3.8f, -2.0f, -12.3f},
        {2.4f, -0.4f, -3.5f},
        {-1.7f, 3.0f, -7.5f},
        {1.3f, -2.0f, -2.5f},
        {1.5f, 2.0f, -2.5f},
        {1.5f, 0.2f, -1.5f},
        {-1.3f, 1.0f, -1.5f}
    };

    // Create Projection Matrix
    mat4 projection;
    glm_mat4_identity(projection);
    glm_perspective(glm_rad(FOV), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f, projection);
    Shader_setMatrix4fv(&shader, "projection", projection);

    // Create Camera
    initCamera(&camera, (vec3){0.0f, 0.0f, 3.0f}, 0.5f);
    

    // Set Clear Buffer Color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        // Update Time
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Clear Buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Bind Texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        // Update Camera
        updateCamera(&camera);
        Shader_setMatrix4fv(&shader, "view", camera.viewMatrix);

        /* Vector Playground 3D */
        for(unsigned int i = 0; i < 10; i++){
            mat4 model;
            glm_mat4_identity(model);

            glm_translate(model, objectPositions[i]);

            float angle = 20.0f * i;
            glm_rotate(model, (float)glfwGetTime() * glm_rad(angle), (vec3){1.0f, 0.3f, 0.5f});

            Shader_setMatrix4fv(&shader, "model", model);

            renderObject(&shader, &object);
        }
        /* End Vector Playground */

        // Render Object(s)
        //renderObject(&shader, &object);

        // Swap Buffers, Poll Events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Exit Gracefully.
    glfwTerminate();
    return 0;
}