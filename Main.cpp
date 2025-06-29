#define IMGUI_IMPL_OPENGL_LOADER_GLAD


#include"imgui.h"
#include"imgui_impl_glfw.h"

#include"imgui_impl_opengl3.h"
//#include"imgui_impl_opengl3_loader.h"

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"
#include"DeltaTime.h"
#include"Tree.h"
#include"Block.h"
#include"WorldStructure.h"


int width = 1920;
int height = 1080;


//technicallllly, its better to include this varriable in Camera.h, and slightly remake the logic in Camera.cpp, then to store it here.
float FOV = 70.0f;



int main()
{


	//Initializes GLFW
	glfwInit();

	//Tells GLFW what version of OpenGL I am using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);



	//Defines the window object
	


	GLFWwindow* window = glfwCreateWindow(width, height, "Voxl Engine", NULL, NULL);


	//Fullscreen
	//GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	//const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	//GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Voxl Engine", monitor, NULL);


	


	//If window failed, create error message
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}


	GLfloat vertices[] =
	{
			//CODE FOR CUBE
			//       Cordinates      /        Colors       // Texture Cordinates
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




	//Loads the Window

	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, width, height);

	//Initalizes all the block textures AFTER gladLoadGL()
	Block::InitTextures();




	//Renders the background color, then applys it to the next frame.

	//glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // == Dark Blue
	glClearColor(0.063f, 0.063f, 0.063f, 1.0f); //== Dark Gray
	//glClearColor(0.106f, 0.624f, 1.0f, 1.0f); //== Sky blue
	//glClearColor(0.753f, 0.847f, 1.0f, 1.0f); //== Sky White

	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	glDisable(GL_DEPTH_TEST);

	glDepthMask(GL_FALSE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	glEnable(GL_TEXTURE_2D);


	//Loads icon image file
	int iconWidth, iconHeight;
	int iconChannels;

	unsigned char* iconPixels = stbi_load("C:/dev/Voxl-Engine/Images/VoxlCube.png", &iconWidth, &iconHeight, &iconChannels, 4);


	//Changes the window icon
	GLFWimage images[1];
	images[0].width = iconWidth;
	images[0].height = iconHeight;
	images[0].pixels = iconPixels;

	glfwSetWindowIcon(window, 1, images);


	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	int indexCount = sizeof(indices) / sizeof(GLuint);

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	//Gets a reference to the Block Database
	auto allBlocks = Block::blockDatabase;

	std::vector<glm::vec3> allPlacedBlocksPos;

	//Gets a reference to all the Block Textures
	auto allBlockTextures = Block::allBlockTextures;

	//Gets both of the array lengths
	int blockDataBaseLength = allBlocks.size();
	int blockTextureBaseLength = allBlocks.size();


	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	DeltaTime deltatime(0.5f);

	//Trees
	Tree OakTree(std::string("Oak"), Block::ReturnBlock("Log"), Block::ReturnBlock("Leaves"));
	Tree LargeOakTree(std::string("Oak_Large"), Block::ReturnBlock("Log"), Block::ReturnBlock("Leaves"));
	Tree FallenLog(std::string("Fallen_Log"), Block::ReturnBlock("Log"), Block::ReturnBlock("Leaves"));
	Tree Rock(std::string("Stone_Rock"), Block::ReturnBlock("Stone"), Block::ReturnBlock("Leaves"));


	WorldStructure Ruins(std::string("Ruins"), 
	{
		Block::ReturnBlock("Darkstone"),
		Block::ReturnBlock("Mossy Darkstone"),
		Block::ReturnBlock("Stone Brick"),
		Block::ReturnBlock("Mossy Stone Brick"),
		Block::ReturnBlock("Cracked Stone Brick")
	});



	//WorldStructure Ruins(std::string("Ruins"), &Stone, &Leaves);

	//Calls for checking for the scroll value
	activeCamera = &camera;
	glfwSetScrollCallback(window, scroll_callback);



	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true); 
	ImGui_ImplOpenGL3_Init("#version 330");


	ImGuiStyle& DevMenuStyle = ImGui::GetStyle();
	DevMenuStyle.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1, 0.0f);
	DevMenuStyle.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.1f, 0.1f, 0.1, 0.0f);

	DevMenuStyle.WindowBorderSize = 0.0f;


	glDisable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
	
	//Block::TotalBlockCount = 0;

	//Main program while loop
	while (!glfwWindowShouldClose(window))
	{
		deltatime.CalculateValues();
		//Does the background color really need to be redefined every frame?
		//glClearColor(0.106f, 0.624f, 1.0f, 1.0f); //== Sky blue
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::SetNextWindowSize(ImVec2(800, 800)); // px

		//All the display data for the developer menu
		ImGui::Begin("Developer Menu", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::Text("FPS: %.2f", deltatime.FPS);
		ImGui::Text("Delta Time: %.10fs", deltatime.DTPS);
		//ImGui::Text("Block Count %i", Block::TotalBlockCount);
		ImGui::Text("Camera Speed %.1f", camera.speed);
		ImGui::Text("Camera Position %.1f, %.1f, %.1f", camera.Position.x, camera.Position.y, camera.Position.z);
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		//Tells OpenGL which shader program to use
		shaderProgram.Activate();

		camera.Inputs(window);
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		camera.Matrix(FOV, 0.1f, 100.0f, shaderProgram, "camMatrix", width, height);


		VAO1.Bind();
		//Draws the shape using the GL Primative, Triangle
	
		

		//Builds a manual set of blocks
		for (int i = 0; i < blockDataBaseLength; i++)
		{
			Block::SpawnBlock(allBlocks[i].DisplayName, glm::vec3((i * 1.0f), 0.0f, 0.0f), shaderProgram);
		}

		//Spawns the 2 trees
		Tree::SpawnTree(glm::vec3(0.0f, 0.0f, 5.0f), OakTree, shaderProgram);
		Tree::SpawnTree(glm::vec3(0.0f, 0.0f, 10.0f), LargeOakTree, shaderProgram);

		//Spawns the 2 foliage
		Tree::SpawnTree(glm::vec3(5.0f, 0.0f, 5.0f), FallenLog, shaderProgram);
		Tree::SpawnTree(glm::vec3(5.0f, 0.0f, 10.0f), Rock, shaderProgram);

		//Spawns the Ruin Structure
		WorldStructure::SpawnStructure(glm::vec3(15.0f, 0.0f, 10.0f), Ruins, shaderProgram);

		//Spawns the stone floor
		Block::SpawnSquareofBlocks("Stone", glm::vec3(15.0f, 0.0f, 10.0f), glm::vec2(-3.0f, 4.0f), glm::vec2(-3.0f, 4.0f), shaderProgram);

		// ! WARNING !, this is a temporary solution, and murders the FPS.
		Block::SpawnSquareofBlocks("Dark Planks", glm::vec3(0.0f, -1.0f, 00.0f), glm::vec2(-25.0f, 25.0f), glm::vec2(-25.0f, 25.0f), shaderProgram);

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			allPlacedBlocksPos.push_back(camera.Position);
		}

		if (allPlacedBlocksPos.empty() == false)
		{
			for (int i = 0; i < allPlacedBlocksPos.size(); i++)
			{
				Block::SpawnBlock("Stone", allPlacedBlocksPos[i], shaderProgram);
			}
		}





		glfwSwapBuffers(window);

		//While window is not closed, allow for input and such.
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	//Deletes all the block textures
	for (int i = 0; i < blockTextureBaseLength; i++)
	{
		allBlockTextures[i].Delete();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}