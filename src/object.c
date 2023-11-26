#include <glad/glad.h>

#include "geometry.h"
#include "object.h"

void createObject(Object *object, Geometry *geometry)
{
    // Generate Object Arrays/Buffers
    glGenVertexArrays(1, &object->VAO);
    glGenBuffers(1, &object->VBO);
    glGenBuffers(1, &object->EBO);

    // Bind Array
    glBindVertexArray(object->VAO);

    // Bind Buffers To Array & Buffer Data
    glBindBuffer(GL_ARRAY_BUFFER, object->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * geometry->numVertices, geometry->vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * geometry->numIndices, geometry->indices, GL_STATIC_DRAW);

    // Link Vertex Attributes
    // NOTE: This needs to be changed later to optimize itself based on what kind of Geometry Data there is, alternateively use the standard. Idk which.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //Unbind Array & Free Geometry
    glBindVertexArray(0);
    freeGeometry(geometry);
}