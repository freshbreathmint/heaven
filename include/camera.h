#ifndef CAMERA_H
#define CAMERA_H

#include <cglm/cglm.h>

#include "shader.h"

typedef struct Camera {
    mat4 viewMatrix;
    vec3 position;
    vec3 target;
    vec3 up;
    vec3 front;
    vec3 right;

    float cameraSpeed;
} Camera;

void initCamera(Camera *camera, vec3 initialPosition, float speed);

void updateCamera(Camera *camera);

void moveCamera(Camera *camera, int key, int action);

#endif // CAMERA_H