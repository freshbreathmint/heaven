#include "render.h"

#include <glad/glad.h>

void renderObject(Shader *shader, Object *object)
{
    Shader_use(shader);
    glBindVertexArray(object->VAO);
    glDrawElements(GL_TRIANGLES, object->numVertices, GL_UNSIGNED_INT, 0);
}