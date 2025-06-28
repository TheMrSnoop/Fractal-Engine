#include"Tree.h"
#include<vector>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


Tree::Tree(const std::string& TreeDisplayName, Texture* LogTexture, Texture* LeafTexture)
{
	if (TreeDisplayName == "Oak")
	{
		std::vector<glm::vec3> OakLogPositions =
		{
			{0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f},
			{0.0f, 2.0f, 0.0f},
			{0.0f, 3.0f, 0.0f}
		};

		std::vector<glm::vec3> OakLeafPositions =
		{
			//Center blocks
			{0.0f, 4.0f, 0.0f},
			{0.0f, 5.0f, 0.0f},
			{0.0f, 6.0f, 0.0f},
			{0.0f, 7.0f, 0.0f},
			//The outmost edges
			{1.0f, 4.0f, 0.0f},
			{1.0f, 5.0f, 0.0f},
			{2.0f, 4.0f, 0.0f},
			{2.0f, 5.0f, 0.0f},

			{-1.0f, 4.0f, 0.0f},
			{-1.0f, 5.0f, 0.0f},
			{-2.0f, 4.0f, 0.0f},
			{-2.0f, 5.0f, 0.0f},

			{0.0f, 4.0f, 1.0f},
			{0.0f, 5.0f, 1.0f},
			{0.0f, 4.0f, 2.0f},
			{0.0f, 5.0f, 2.0f},

			{0.0f, 4.0f, -1.0f},
			{0.0f, 5.0f, -1.0f},
			{0.0f, 4.0f, -2.0f},
			{0.0f, 5.0f, -2.0f},
			//Filling it in
			{1.0f, 4.0f, 1.0f},
			{1.0f, 5.0f, 1.0f},

			{2.0f, 4.0f, 1.0f},
			{2.0f, 5.0f, 1.0f},

			{1.0f, 4.0f, 2.0f},
			{1.0f, 5.0f, 2.0f},
			//{2.0f, 4.0f, 2.0f},
			//{2.0f, 5.0f, 2.0f},
			{-1.0f, 4.0f, 1.0f},
			{-1.0f, 5.0f, 1.0f},

			{-2.0f, 4.0f, 1.0f},
			{-2.0f, 5.0f, 1.0f},

			{-1.0f, 4.0f, 2.0f},
			{-1.0f, 5.0f, 2.0f},

			{-2.0f, 4.0f, 2.0f},
			//{-2.0f, 5.0f, 2.0f},
			{1.0f, 4.0f, -1.0f},
			{1.0f, 5.0f, -1.0f},

			{2.0f, 4.0f, -1.0f},
			{2.0f, 5.0f, -1.0f},

			{1.0f, 4.0f, -2.0f},
			{1.0f, 5.0f, -2.0f},
			//{2.0f, 4.0f, -2.0f},
			//{2.0f, 5.0f, -2.0f},
			{-1.0f, 4.0f, -1.0f},
			{-1.0f, 5.0f, -1.0f},

			{-2.0f, 4.0f, -1.0f},
			{-2.0f, 5.0f, -1.0f},

			{-1.0f, 4.0f, -2.0f},
			{-1.0f, 5.0f, -2.0f},

			{-2.0f, 4.0f, -2.0f},
			{-2.0f, 5.0f, -2.0f},


			//The very top
			{ 1.0f, 6.0f, 0.0f },
			{ -1.0f, 6.0f, 0.0f },
			{ 0.0f, 6.0f, -1.0f },
			{ 0.0f, 6.0f, 1.0f },
		};



		// trunk
		TreePart trunk;
		trunk.textureRef = LogTexture;
		trunk.relativePos = OakLogPositions;
		parts.push_back(trunk);

		// leaves
		TreePart leaves;
		leaves.textureRef = LeafTexture;
		leaves.relativePos = OakLeafPositions;
		parts.push_back(leaves);
	}
	else if (TreeDisplayName == "Oak_Large")
	{
		std::vector<glm::vec3> OakLogPositions =
		{
			//Trunk
			{0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f},
			{0.0f, 2.0f, 0.0f},
			{0.0f, 3.0f, 0.0f},
			{0.0f, 4.0f, 0.0f},
			{0.0f, 5.0f, 0.0f},
			{0.0f, 6.0f, 0.0f},
			{0.0f, 7.0f, 0.0f},

			//Branch
			{1.0f, 4.0f, 0.0f},
			{2.0f, 4.0f, 0.0f},
			{2.0f, 5.0f, 0.0f},
		};

		std::vector<glm::vec3> OakLeafPosistions =
		{
			//Center blocks
			{0.0f, 8.0f, 0.0f},
			{0.0f, 9.0f, 0.0f},
			{0.0f, 10.0f, 0.0f},
			//The outmost edges
			{1.0f, 8.0f, 0.0f},
			{1.0f, 9.0f, 0.0f},
			{2.0f, 8.0f, 0.0f},
			{2.0f, 9.0f, 0.0f},

			{-1.0f, 8.0f, 0.0f},
			{-1.0f, 9.0f, 0.0f},
			{-2.0f, 8.0f, 0.0f},
			{-2.0f, 9.0f, 0.0f},

			{0.0f, 8.0f, 1.0f},
			{0.0f, 9.0f, 1.0f},
			{0.0f, 8.0f, 2.0f},
			{0.0f, 9.0f, 2.0f},

			{0.0f, 8.0f, -1.0f},
			{0.0f, 9.0f, -1.0f},
			{0.0f, 8.0f, -2.0f},
			{0.0f, 9.0f, -2.0f},
			//Filling it in
			{1.0f, 8.0f, 1.0f},
			{1.0f, 9.0f, 1.0f},

			{2.0f, 8.0f, 1.0f},
			{2.0f, 9.0f, 1.0f},

			{1.0f, 8.0f, 2.0f},
			{1.0f, 9.0f, 2.0f},
			//{2.0f, 8.0f, 2.0f},
			//{2.0f, 9.0f, 2.0f},
			{-1.0f, 8.0f, 1.0f},
			{-1.0f, 9.0f, 1.0f},

			{-2.0f, 8.0f, 1.0f},
			{-2.0f, 9.0f, 1.0f},

			{-1.0f, 8.0f, 2.0f},
			{-1.0f, 9.0f, 2.0f},

			{-2.0f, 8.0f, 2.0f},
			//{-2.0f, 9.0f, 2.0f},
			{1.0f, 8.0f, -1.0f},
			{1.0f, 9.0f, -1.0f},

			{2.0f, 8.0f, -1.0f},
			{2.0f, 9.0f, -1.0f},

			{1.0f, 8.0f, -2.0f},
			{1.0f, 9.0f, -2.0f},
			//{2.0f, 8.0f, -2.0f},
			//{2.0f, 9.0f, -2.0f},
			{-1.0f, 8.0f, -1.0f},
			{-1.0f, 9.0f, -1.0f},

			{-2.0f, 8.0f, -1.0f},
			{-2.0f, 9.0f, -1.0f},

			{-1.0f, 8.0f, -2.0f},
			{-1.0f, 9.0f, -2.0f},

			{-2.0f, 8.0f, -2.0f},
			{-2.0f, 9.0f, -2.0f},



			//The very bottom
			{ 1.0f, 7.0f, 0.0f },
			{ -1.0f, 7.0f, 0.0f },
			{ 0.0f, 7.0f, -1.0f },
			{ 0.0f, 7.0f, 1.0f },

			//The very top
			{ 1.0f, 10.0f, 0.0f },
			{ -1.0f, 10.0f, 0.0f },
			{ 0.0f, 10.0f, -1.0f },
			{ 0.0f, 10.0f, 1.0f },

			{ 1.0f, 10.0f, 1.0f },
			{ -1.0f, 10.0f, 1.0f },
			{ -1.0f, 10.0f, -1.0f },
			{ 1.0f, 10.0f, -1.0f },


			//Branch Leaves
			{ 2.0f, 6.0f, 0.0f },
			{ 1.0f, 5.0f, 0.0f },
			{ 3.0f, 5.0f, 0.0f },

			{ 2.0f, 5.0f, -1.0f },
			{ 2.0f, 5.0f, 1.0f },


		

			//Smaller Branch Leaves
			{ 0.0f, 4.0f, 1.0f },
			{ 0.0f, 3.0f, 1.0f },
			{ -1.0f, 4.0f, 0.0f },
			{ -1.0f, 3.0f, 0.0f },
			{ -1.0f, 2.0f, 0.0f },
			{ 0.0f, 2.0f, -1.0f },
			{ 1.0f, 1.0f, 0.0f },

		};


		// trunk
		TreePart trunk;
		trunk.textureRef = LogTexture;
		trunk.relativePos = OakLogPositions;
		parts.push_back(trunk);

		// leaves
		TreePart leaves;
		leaves.textureRef = LeafTexture;
		leaves.relativePos = OakLeafPosistions;
		parts.push_back(leaves);
	}
	else if(TreeDisplayName == "Fallen_Log")
	{
		std::vector<glm::vec3> FallenLogPositions =
		{
			//Trunk
			{1.0f, 0.0f, 0.0f},
			{2.0f, 0.0f, 0.0f},
			{3.0f, 0.0f, 0.0f},
			{4.0f, 0.0f, 0.0f},
			{5.0f, 0.0f, 0.0f}
		};

		TreePart trunk;
		trunk.textureRef = LogTexture;
		trunk.relativePos = FallenLogPositions;
		parts.push_back(trunk);
	}
	else if (TreeDisplayName == "Stone_Rock")
	{
		std::vector<glm::vec3> StonePositions =
		{
			//Rock Body
			{0.0f, 0.0f, 0.0f},
			{1.0f, 0.0f, 0.0f},
			{-1.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f},
			{0.0f, 0.0f, -1.0f},

			{0.0f, 1.0f, 0.0f},
			{0.0f, 1.0f, 1.0f}
		};

		TreePart trunk;
		trunk.textureRef = LogTexture;
		trunk.relativePos = StonePositions;
		parts.push_back(trunk);
	}
		
}