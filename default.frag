#version 330 core
out vec4 FragColor;

//Inputs the color value outputted by the default.vert
in vec3 color;
in vec2 texCoord;

uniform sampler2D tex0;

void main()
{
	FragColor = texture(tex0, texCoord);

	//allows for transparent textures

	if (FragColor.a < 0.1)
		discard;
};