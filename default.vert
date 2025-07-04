#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

// Outputs the color for the Fragment Shader
out vec3 color;

out vec2 texCoord;

uniform mat4 camMatrix;

void main()
{
	gl_Position = camMatrix * vec4(aPos, 1.0);
	//Assigns the color for the Fragment Shader
	color = aColor;
	texCoord = aTex;
};