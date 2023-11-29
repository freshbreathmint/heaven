#version 460 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D textureInput;

void main()
{
    FragColor = texture(textureInput, TexCoord);
}