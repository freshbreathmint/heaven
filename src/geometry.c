#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "geometry.h"

// Function to free the memory allocated for vertex and indices, then set the array sizes back to zero.
void freeGeometry(Geometry *geometry)
{
    free(geometry->vertices);
    free(geometry->indices);
    geometry->numVertices = 0;
    geometry->numIndices = 0;
}

// Function to read the geometry from a file
void readGeometry(Geometry *geometry, const char *filename)
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
    geometry->vertices = malloc(numVertices * sizeof(float));
    geometry->indices = malloc(numIndices * sizeof(unsigned int));

    // Check if memory allocation was successful
    if (geometry->vertices == NULL || geometry->indices == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file);
        return;
    }

    // Reset file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    size_t vertexIndex = 0;
    size_t indexIndex = 0;

    // Second pass: populate arrays
    while (fscanf(file, "%s", valueStr) == 1)
    {
        // If the value contains a decimal point, it's a vertex
        if (strchr(valueStr, '.') != NULL)
        {
            geometry->vertices[vertexIndex++] = atof(valueStr);
        }
        // If the value doesn't contain a decimal point, it's an index
        else
        {
            
            geometry->indices[indexIndex++] = atoi(valueStr);
        }
    }

    // Set the number of vertices and indices
    geometry->numVertices = numVertices;
    geometry->numIndices = numIndices;

    // Close the file
    fclose(file);
}