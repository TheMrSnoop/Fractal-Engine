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


int width = 1920;
int height = 1080;



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


	//Renders the background color, then applys it to the next frame.

	//glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // == Dark Blue
	glClearColor(0.063f, 0.063f, 0.063f, 1.0f); //== Dark Gray
	//glClearColor(0.106f, 0.624f, 1.0f, 1.0f); //== Sky blue
	//glClearColor(0.753f, 0.847f, 1.0f, 1.0f); //== Sky White

	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


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



	//Texture

	//Creates the texture object
	Texture Grass("C:/dev/Voxl-Engine/Images/BlockTextures/Grass.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture Dirt("C:/dev/Voxl-Engine/Images/BlockTextures/Dirt.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture Log("C:/dev/Voxl-Engine/Images/BlockTextures/Log.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture Leaves("C:/dev/Voxl-Engine/Images/BlockTextures/Leaves.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

	Texture DarkPlanks("C:/dev/Voxl-Engine/Images/BlockTextures/DarkPlanks.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture Glass("C:/dev/Voxl-Engine/Images/BlockTextures/Glass.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

	Texture Darkstone("C:/dev/Voxl-Engine/Images/BlockTextures/Darkstone.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture MossyDarkstone("C:/dev/Voxl-Engine/Images/BlockTextures/MossyDarkstone.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);

	Texture Stone("C:/dev/Voxl-Engine/Images/BlockTextures/Stone.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);

	Texture IronOre("C:/dev/Voxl-Engine/Images/BlockTextures/IronOre.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture DiamondOre("C:/dev/Voxl-Engine/Images/BlockTextures/DiamondOre.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture GoldOre("C:/dev/Voxl-Engine/Images/BlockTextures/GoldOre.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture EmeraldOre("C:/dev/Voxl-Engine/Images/BlockTextures/EmeraldOre.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture CoalOre("C:/dev/Voxl-Engine/Images/BlockTextures/CoalOre.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture RubyOre("C:/dev/Voxl-Engine/Images/BlockTextures/RubyOre.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture OpalOre("C:/dev/Voxl-Engine/Images/BlockTextures/OpalOre.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);



	Texture Obsidian("C:/dev/Voxl-Engine/Images/BlockTextures/Obsidian.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture Sand("C:/dev/Voxl-Engine/Images/BlockTextures/Sand.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Texture Lava("C:/dev/Voxl-Engine/Images/BlockTextures/Lava.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);

	Texture Water("C:/dev/Voxl-Engine/Images/BlockTextures/Water.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	//brick.texUnit(shaderProgram, "tex0", 0);

	//Assigns the texture objects to an array
	//With the current debug system I have in place, the order of this array defines the order of the blocks when they spawn.
	Texture textures[] = { Grass, Dirt, Log, Leaves, DarkPlanks, Glass, MossyDarkstone, Darkstone, Stone, IronOre, DiamondOre, EmeraldOre, CoalOre, RubyOre, OpalOre, Sand, Water, Obsidian, Lava };

	int TextureLength = sizeof(textures) / sizeof(textures[0]);


	glEnable(GL_DEPTH_TEST);


	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	DeltaTime deltatime(0.5f);


	Tree OakTree(std::string("Oak"), &Log, &Leaves);
	Tree LargeOakTree(std::string("Oak_Large"), &Log, &Leaves);
	Tree FallenLog(std::string("Fallen_Log"), &Log, &Leaves);
	Tree Rock(std::string("Stone_Rock"), &Stone, &Leaves);

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


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
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
		ImGui::Text("Block Count %i", TextureLength);
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
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix", width, height);



		VAO1.Bind();
		//Draws the shape using the GL Primative, Triangle
	
		

		//Builds a manual set of blocks
		for (int i = 0; i < TextureLength; i++)
		{
			Block newBlock(Block::Natural, textures[i], 1.0f, glm::vec3((i * 1.0f), 0.0f, 0.0f), EBO1.ID, indexCount, shaderProgram);
		}




		//Cycles through both the log and leaf parts to build the tree.
		// (Since the trunk is defined first, it builds the trunk, then the leaves)
		for (auto& part : OakTree.parts)
		{
			part.textureRef->Bind();
			for (auto& offset : part.relativePos)
			{
				//Defines where the tree will be placed
				glm::vec3 worldPos = (glm::vec3(0, 0, 0) + offset) + glm::vec3(0, 0, 5);

				//Likely caused by part.textureRef
				Block newBlock(Block::Natural, part.textureRef, 1.0f, worldPos, EBO1.ID, indexCount, shaderProgram);
			}
		}

		//Large Oak Tree
		for (auto& part : LargeOakTree.parts)
		{
			part.textureRef->Bind();
			for (auto& offset : part.relativePos)
			{
				//Defines where the tree will be placed
				glm::vec3 worldPos = (glm::vec3(0, 0, 0) + offset) + glm::vec3(0, 0, 15);


				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, worldPos);
				shaderProgram.setMat4("model", model);
				glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
			}
		}

		//Fallen Log
		for (auto& part : FallenLog.parts)
		{
			part.textureRef->Bind();
			for (auto& offset : part.relativePos)
			{
				//Defines where the tree will be placed
				glm::vec3 worldPos = (glm::vec3(0, 0, 0) + offset) + glm::vec3(5, 0, 15);


				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, worldPos);
				shaderProgram.setMat4("model", model);
				glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
			}
		}

		//For Rock
		for (auto& part : Rock.parts)
		{
			part.textureRef->Bind();
			for (auto& offset : part.relativePos)
			{
				//Defines where the tree will be placed
				glm::vec3 worldPos = (glm::vec3(0, 0, 0) + offset) + glm::vec3(5, 0, 5);


				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, worldPos);
				shaderProgram.setMat4("model", model);
				glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
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
	//brick.Delete();
	shaderProgram.Delete();

	for (int i = 0; i < 5; i++)
	{
		textures[i].Delete();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}