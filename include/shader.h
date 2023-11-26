#ifndef SHADER_H
#define SHADER_H

typedef struct {
    unsigned int ID;
} Shader;

void Shader_init(Shader *shader, const char *vertexPath, const char *fragmentPath);
void Shader_use(const Shader *shader);

#endif // SHADER_H