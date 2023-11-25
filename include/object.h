#ifndef OBJECT_H
#define OBJECT_H

typedef struct Object {
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
} Object;

void createObject(Object *object, float *vertices, unsigned int *indices, size_t numVertices, size_t numIndices);

#endif //OBJECT_H