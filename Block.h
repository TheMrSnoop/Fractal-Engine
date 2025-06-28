#pragma once
#include "Texture.h"
#include"shaderClass.h"

class Block
{
public:
	enum BlockType
	{
		Natural, // also fixed typo
		Crafted
	};

	Block(BlockType type, Texture blockTexture, float blockDurability, glm::vec3 position, GLuint indices, int indexCount, Shader shaderProgram);

};
