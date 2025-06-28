#pragma once
#include <iostream>
#include <vector>
#include <glm/glm.hpp> 
#include "Texture.h"

class Tree
{
public:
	struct TreePart {
		Texture* textureRef;
		std::vector<glm::vec3> relativePos;
	};

	std::vector<TreePart> parts; 

	Tree(const std::string& TreeDisplayName, Texture* LogTexture, Texture* LeafTexture);
};
