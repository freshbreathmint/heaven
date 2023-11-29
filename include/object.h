#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

typedef struct Object {
    // Buffers
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    // Geometry
    float *vertices;
    unsigned int *indices;
    size_t numVertices;
    size_t numIndices;
} Object;

void createObject(Object *object, const char *filename);

#endif // OBJECT_H