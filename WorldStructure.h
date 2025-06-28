#pragma once
#include <vector>
#include "Texture.h"
#include "Block.h"
#include <iostream>

class WorldStructure
{
public:
	struct StructurePart
	{
		Block block;
		std::vector<glm::vec3> relativePos;
	};

	std::vector<StructurePart> StructureParts;

	WorldStructure(std::string StructureID, Block block[], std::vector<glm::vec3> relativePos[]);
};