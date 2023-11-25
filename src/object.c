#include <glad/glad.h>

#include "object.h"

void createObject(Object *object, float *vertices, unsigned int *indices, size_t numVertices, size_t numIndices)
{
    // Generate Object Arrays/Buffers
    glGenVertexArrays(1, &object->VAO);
    glGenBuffers(1, &object->VBO);
    glGenBuffers(1, &object->EBO);

    // Bind Array
    glBindVertexArray(object->VAO);

    // Bind Buffers To Array & Buffer Data
    glBindBuffer(GL_ARRAY_BUFFER, object->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numVertices, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * numIndices, indices, GL_STATIC_DRAW);

    // Link Vertex Attributes
    // NOTE: This needs to be changed later to optimize itself based on what kind of Geometry Data there is, alternateively use the standard. Idk which.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //Unbind Array
    glBindVertexArray(0);
}