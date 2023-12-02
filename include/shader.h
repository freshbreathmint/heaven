#ifndef SHADER_H
#define SHADER_H

#include <cglm/cglm.h>
#include <glad/glad.h>

typedef struct {
    unsigned int ID;
} Shader;

void Shader_init(Shader *shader, const char *vertexPath, const char *fragmentPath);
void Shader_use(const Shader *shader);

void Shader_setBool(const Shader *shader, const char *name, int value);
void Shader_setInt(const Shader *shader, const char *name, int value);
void Shader_setFloat(const Shader *shader, const char *name, int value);
void Shader_setFloat4(const Shader *shader, const char *name, float f1, float f2, float f3, float f4);
void Shader_setMatrix4fv(const Shader *shader, const char *name, mat4 data);

#endif // SHADER_H