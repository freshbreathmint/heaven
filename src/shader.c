#include <stdio.h>

#include <glad/glad.h>

#include "readfile.h"

#include "shader.h"

// Compile Shader
unsigned int compileShader(unsigned int shaderType, const char *shaderSource, const char *shaderName)
{
    int success;
    char infoLog[512];

    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("%s Shader Failed To Compile: %s\n", shaderName, infoLog);
    }

    return shader;
}

// Link Shader
void linkShaders(unsigned int *shaderProgram, unsigned int vertexShader, unsigned int fragmentShader)
{
    int success;
    char infoLog[512];

    *shaderProgram = glCreateProgram();
    glAttachShader(*shaderProgram, vertexShader);
    glAttachShader(*shaderProgram, fragmentShader);
    glLinkProgram(*shaderProgram);

    glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(*shaderProgram, 512, NULL, infoLog);
        printf("Shader Program Failed To Link: %s\n", infoLog);
    }
}

void Shader_init(Shader *shader, const char *vertexPath, const char *fragmentPath)
{
    // Read Shaders
    char *vertexShaderSource = readFile(vertexPath);
    char *fragmentShaderSource = readFile(fragmentPath);

    // Compile Shaders
    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource, "Vertex");
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource, "Fragment");

    // Link Shaders
    linkShaders(&(shader->ID), vertexShader, fragmentShader);

    // Clean Up
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    freeFile(vertexShaderSource);
    freeFile(fragmentShaderSource);
}

void Shader_use(const Shader *shader)
{
    glUseProgram(shader->ID);
}

void Shader_setBool(const Shader *shader, const char *name, int value)
{
    glUniform1i(glGetUniformLocation(shader->ID, name), value);
}

void Shader_setInt(const Shader *shader, const char *name, int value)
{
    glUniform1i(glGetUniformLocation(shader->ID, name), value);
}

void Shader_setFloat(const Shader *shader, const char *name, int value)
{
    glUniform1f(glGetUniformLocation(shader->ID, name), value);
}

void Shader_setColor(const Shader *shader, const char *name, float r, float g, float b, float a)
{
    glUniform4f(glGetUniformLocation(shader->ID, name), r, g, b, a);
}