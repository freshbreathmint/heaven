#ifndef OBJECT_H
#define OBJECT_H

typedef struct Object {
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
} Object;

void createObject(Object *object, Geometry *geometry);

#endif // OBJECT_H