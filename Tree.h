#pragma once
#include <iostream>
#include <vector>
#include <glm/glm.hpp> 
#include "Texture.h"
#include "Block.h"
#include"shaderClass.h"

class Tree
{
public:
	struct TreePart {
		Block::BlockData treeBlock;
		std::vector<glm::vec3> relativePos;
	};

	std::vector<TreePart> parts; 
	
	static void SpawnTree(glm::vec3 TreePosition, Tree treeObject, Shader shaderProgram);

	Tree(const std::string& TreeDisplayName, const Block::BlockData& trunkBlock, const Block::BlockData& leafBlock);
};
