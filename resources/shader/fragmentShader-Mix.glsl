#version 460 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D textureInput1;
uniform sampler2D textureInput2;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = mix(texture(textureInput1, TexCoord), texture(textureInput2, TexCoord), 0.2) * vec4(ourColor, 1.0);
}