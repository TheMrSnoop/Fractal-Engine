#include "Block.h"
#include "Texture.h"
#include<iostream>
#include<string>
#include <vector>


//Defines all the vertices for a cube

GLfloat vertices[] =
{
	//CODE FOR CUBE
	//     Cordinates   /     Colors      // Texture Cordinates
	// FRONT
	-0.5f, -0.5f, 0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 0.0f,
	 0.5f, -0.5f, 0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 0.0f,
	 0.5f,  0.5f, 0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 1.0f,
	-0.5f,  0.5f, 0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 1.0f,

	// BACK
	0.5f, -0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 0.0f,
   -0.5f, -0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 0.0f,
   -0.5f,  0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 1.0f,
	0.5f,  0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 1.0f,

	// LEFT
   -0.5f, -0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 0.0f,
   -0.5f, -0.5f,  0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 0.0f,
   -0.5f,  0.5f,  0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 1.0f,
   -0.5f,  0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 1.0f,

   // RIGHT
   0.5f, -0.5f,  0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 0.0f,
   0.5f, -0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 0.0f,
   0.5f,  0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 1.0f,
   0.5f,  0.5f,  0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 1.0f,

   // TOP
  -0.5f, 0.5f,  0.5f,    0.8f, 0.7f, 0.4f,    0.0f, 0.0f,
   0.5f, 0.5f,  0.5f,    0.8f, 0.7f, 0.4f,    1.0f, 0.0f,
   0.5f, 0.5f, -0.5f,    0.8f, 0.7f, 0.4f,    1.0f, 1.0f,
  -0.5f, 0.5f, -0.5f,    0.8f, 0.7f, 0.4f,    0.0f, 1.0f,

  // BOTTOM
 -0.5f, -0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 0.0f,
  0.5f, -0.5f, -0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 0.0f,
  0.5f, -0.5f,  0.5f,   0.8f, 0.7f, 0.4f,    1.0f, 1.0f,
 -0.5f, -0.5f,  0.5f,   0.8f, 0.7f, 0.4f,    0.0f, 1.0f

 //CODE FOR PYRAMID
 //       Cordinates      /        Colors       // Texture Cordinates
 //-0.5f,  0.0f,   0.5f,      0.83f, 0.70f, 0.44f,    0.0f, 0.0f,  
 //-0.5f,  0.0f,  -0.5f,      0.83f, 0.70f, 0.44f,    5.0f, 0.0f,  
 //0.5f,  0.0f,  -0.5f,      0.83f, 0.70f, 0.44f,    0.0f, 0.0f,  
 //0.5f,  0.0f,   0.5f,      0.83f, 0.70f, 0.44f,    5.0f, 0.0f,   
 //0.0f,  0.8f,   0.0f,      0.92f, 0.86f, 0.76f,    2.5f, 5.0f 

 //CODE FOR SQUARE/PLANE
 //       Cordinates      /        Colors       // Texture Cordinates
 //-0.5f, -0.5f, 0.0f,      1.0f, 0.0f, 0.0f,    0.0f, 0.0f,   //Lower left corner
 //-0.5f, 0.5f,  0.0f,      0.0f, 1.0f, 0.0f,    0.0f, 1.0f,   //Upper left corner
 //0.5f, 0.5f, 0.0f,        0.0f, 0.6f, 1.0f,    1.0f, 1.0f,   //Upper right corner
 //0.5f, -0.5f, 0.0f,       1.0f, 1.0f, 1.0f,    1.0f, 0.0f    //Lower right corner
};


//Describes the indices for the cube
//In other words, describes in which order the vertices should be drawn
//This code is specific for a cube mesh
GLuint indices[] =
{
	0, 1, 2,    2, 3, 0,      // front
	4, 5, 6,    6, 7, 4,      // back
	8, 9,10,   10,11, 8,      // left
   12,13,14,   14,15,12,      // right
   16,17,18,   18,19,16,      // top
   20,21,22,   22,23,20       // bottom

   //INDICES FOR PYRAMID
   //0, 1, 2,
   //0, 2, 3,
   //0, 1, 4,
   //1, 2, 4,
   //2, 3, 4,
   //3, 0, 4

   //INDICES FOR SQUARE/PLANE
   //0, 2, 1, //Upper triangle
   //0, 3, 2 //Lower triangle
};


//Initalizes all the texture objects by creating the array of textures, given the file path
//Then, every Block's "blockTextureIndex" is then "linked" to the index of the Texture Array

//For example, when the Dirt texture is being created, the index of that Texture is stored into the Dirt Block, which can then be later used in reference to that block.

//! NOTE !//
//This will only work if the 2 arrays are synced up. Ex: DirtBlock is element 3, and DirtBlockTexture is element 3.

void Block::InitTextures()
{
	Block::allBlockTextures.reserve(blockDatabase.size());

	for (int i = 0; i < blockDatabase.size(); i++)
	{
		GLenum format = GL_RGB;
		if (blockDatabase[i].texturePath.size() >= 4 && blockDatabase[i].texturePath.substr(blockDatabase[i].texturePath.size() - 4) == ".png")
		{
			format = GL_RGBA;
		}

		Block::allBlockTextures.emplace_back(
			blockDatabase[i].texturePath.c_str(),
			GL_TEXTURE_2D,
			GL_TEXTURE0,
			format,
			GL_UNSIGNED_BYTE
		);

		blockDatabase[i].blockTextureIndex = i;
	}

}



//ALL THE BLOCKS IN THE GAME NEED TO FIRST BE DEFINED HERE.
//Display Name | Block Type | Path to Texture | Durrability (can be used if I want to add gameplay)
std::vector<Block::BlockData> Block::blockDatabase =
{
	{"Grass Top", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/GrassTop.jpg", 5.0f},
	{"Grass", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/Grass.jpg", 5.0f},
	{"Dirt", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/Dirt.jpg", 5.0f},
	{"Log", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/Log.jpg", 10.0f},
	{"Pine Log", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/PineLog.jpg", 10.0f},
	{"Leaves", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/Leaves.png", 2.5f},
	{"Pine Leaves", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/PineLeaves.png", 2.5f},

	{"Dark Planks", Block::Crafted, "C:/dev/Voxl-Engine/Images/BlockTextures/DarkPlanks.jpg", 10.0f},
	{"Chest", Block::Crafted, "C:/dev/Voxl-Engine/Images/BlockTextures/Chest.jpg", 10.0f},
	{"Glass", Block::Crafted, "C:/dev/Voxl-Engine/Images/BlockTextures/Glass.png", 10.0f},
	{"Darkstone", Block::Crafted, "C:/dev/Voxl-Engine/Images/BlockTextures/Darkstone.jpg", 15.0f},
	{"Mossy Darkstone", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/MossyDarkstone.jpg", 15.0f},

	{"Stone", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/Stone.jpg", 15.0f},

	{"Stone Brick", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/StoneBrick.jpg", 15.0f},
	{"Mossy Stone Brick", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/MossyStoneBrick.jpg", 15.0f},
	{"Cracked Stone Brick", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/CrackedStoneBrick.jpg", 15.0f},

	{"Iron Ore", Block::Ore, "C:/dev/Voxl-Engine/Images/BlockTextures/IronOre.jpg", 20.0f},
	{"Diamond Ore", Block::Ore, "C:/dev/Voxl-Engine/Images/BlockTextures/DiamondOre.jpg", 20.0f},
	{"Gold Ore", Block::Ore, "C:/dev/Voxl-Engine/Images/BlockTextures/GoldOre.jpg", 20.0f},
	{"Emerald Ore", Block::Ore, "C:/dev/Voxl-Engine/Images/BlockTextures/EmeraldOre.jpg", 20.0f},
	{"Coal Ore", Block::Ore, "C:/dev/Voxl-Engine/Images/BlockTextures/CoalOre.jpg", 20.0f},
	{"Ruby Ore", Block::Ore, "C:/dev/Voxl-Engine/Images/BlockTextures/RubyOre.jpg", 20.0f},
	{"Opal Ore", Block::Ore, "C:/dev/Voxl-Engine/Images/BlockTextures/OpalOre.jpg", 20.0f},

	{"Obsidian", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/Obsidian.jpg", 100.0f},
	{"Sand", Block::Natural, "C:/dev/Voxl-Engine/Images/BlockTextures/Sand.jpg", 5.0f},
	{"Lava", Block::Liquid, "C:/dev/Voxl-Engine/Images/BlockTextures/Lava.jpg", 1.0f},
	{"Water", Block::Liquid, "C:/dev/Voxl-Engine/Images/BlockTextures/Water.png", 1.0f},

};

std::vector<Texture> Block::allBlockTextures;

//Loops through the database to find an element that's name matches the input name

Block::BlockData Block::ReturnBlock(std::string BlockDataID)
{
	for (int i = 0; i < blockDatabase.size(); i++)
	{
		if (Block::blockDatabase[i].DisplayName == BlockDataID)
		{
			Block::BlockData foundBlock = Block::blockDatabase[i];
			return foundBlock;
			break;
		} 
	}
}





//Required for SpawnBlock
int indexCount = sizeof(indices) / sizeof(GLuint);

//Spawns the block, given the ID, position, and a reference to the shaderProgram

void Block::SpawnBlock(std::string BlockDataID, glm::vec3 position, Shader shaderProgram)
{
	//Block::TotalBlockCount += 1;

	//Ensures that the block "snaps" to a grid
	glm::vec3 roundedPosition = glm::vec3(round(position.x) * 1.0f, round(position.y) * 1.0f, round(position.z) * 1.0f);


	//Gets a ref
	Block::BlockData blockReference = ReturnBlock(BlockDataID);

	//Binds the correct texture
	Block::allBlockTextures[blockReference.blockTextureIndex].Bind();


	//Actually spawns/draws the block
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, roundedPosition);
	shaderProgram.setMat4("model", model);

	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

}


void Block::SpawnSquareofBlocks(std::string BlockDataID, glm::vec3 position, glm::vec2 sizeX, glm::vec2 sizeZ, Shader shaderProgram)
{
	//sizeX and sizeZ output a vector2 of (x, y)
	//in this usecase, X is minimum, and Y is maximum

	glm::vec3 relativeOffset = glm::vec3(0.0f, 0.0f, 0.0f);

	for (int z = sizeZ.x; z < sizeZ.y; z++)
	{
		for (int x = sizeX.x; x < sizeX.y; x++)
		{
			relativeOffset = glm::vec3(x * 1.0f, 0.0f, z * 1.0f);
			Block::SpawnBlock(BlockDataID, relativeOffset + position, shaderProgram);
		}
	}


}


