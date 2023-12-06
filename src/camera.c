#include "camera.h"

#include <GLFW/glfw3.h>

void initCamera(Camera *camera, vec3 initialPosition, float speed) 
{
    glm_mat4_identity(camera->viewMatrix);
    glm_vec3_copy(initialPosition, camera->position);
    glm_vec3_copy((vec3){0.0f, 0.0f, 0.0f}, camera->target);
    glm_vec3_copy((vec3){0.0f, 1.0f, 0.0f}, camera->up);
    glm_vec3_copy((vec3){0.0f, 0.0f, -1.0f}, camera->front);
    glm_vec3_cross(camera->front, camera->up, camera->right);
    glm_normalize(camera->right);
    camera->cameraSpeed = speed;
}

void updateCamera(Camera *camera)
{
    glm_lookat(camera->position, camera->target, camera->up, camera->viewMatrix);
}

void moveCamera(Camera *camera, int key, int action)
{
    
}