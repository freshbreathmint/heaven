#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stddef.h>

typedef struct Geometry {
    float *vertices;
    unsigned int *indices;
    size_t numVertices;
    size_t numIndices;
} Geometry;

void freeGeometry(Geometry *geometry);

void readGeometry(Geometry *geometry, const char *filename);

#endif // GEOMETRY_H