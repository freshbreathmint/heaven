#include <stdio.h>
#include <string.h>

#include <glad/glad.h>

#include "object.h"

//this needs to be rewritten again
void readGeometry(Object *object, const char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    // Buffer to hold the value read from the file
    char valueStr[32];
    size_t numVertices = 0;
    size_t numIndices = 0;

    // First pass: count vertices and indices
    while (fscanf(file, "%s", valueStr) == 1)
    {
        // If the value contains a decimal point, it's a vertex
        if (strchr(valueStr, '.') != NULL)
        {
            numVertices++;
        }
        // If the value doesn't contain a decimal point, it's an index
        else
        {
            
            numIndices++;
        }
    }

    // Allocate memory for vertices and indices
    object->vertices = malloc(numVertices * sizeof(float));
    object->indices = malloc(numIndices * sizeof(unsigned int));

    // Check if memory allocation was successful
    if (object->vertices == NULL || object->indices == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file);
        return;
    }

    // Reset file pointer to the beginning
    rewind(file);

    size_t vertexIndex = 0;
    size_t indexIndex = 0;

    // Second pass: populate arrays
    while (fscanf(file, "%s", valueStr) == 1)
    {
        // If the value contains a decimal point, it's a vertex
        if (strchr(valueStr, '.') != NULL)
        {
            object->vertices[vertexIndex++] = atof(valueStr);
        }
        // If the value doesn't contain a decimal point, it's an index
        else
        {
            
            object->indices[indexIndex++] = atoi(valueStr);
        }
    }

    // Update Object
    object->numVertices = numVertices;
    object->numIndices = numIndices;

    // Close the file
    fclose(file);
}

void createObject(Object *object, const char *filename)
{
    // Generate Object Arrays/Buffers
    glGenVertexArrays(1, &object->VAO);
    glGenBuffers(1, &object->VBO);
    glGenBuffers(1, &object->EBO);

    // Read Geometry Data
    readGeometry(object, filename);

    // Bind Array
    glBindVertexArray(object->VAO);

    // Bind Buffers To Array & Buffer Data
    glBindBuffer(GL_ARRAY_BUFFER, object->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * object->numVertices, object->vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * object->numIndices, object->indices, GL_STATIC_DRAW);

    // Link Attributes
    // TODO: Figure out how to make this modular? Alternatively, figure out something that just works.
    
    // Vertex:
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color:
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    //Unbind Array & Free Geometry Data
    glBindVertexArray(0);
    free(object->vertices);
    free(object->indices);
}