#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<stb/stb_image.h>


#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"



int main()
{


	//Initializes GLFW
	glfwInit();

	//Tells GLFW what version of OpenGL I am using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	//Defines the window object, lowkey looks like a pointer...

	GLFWwindow* window = glfwCreateWindow(800, 800, "Voxl Engine", NULL, NULL);

	//If window failed, create error message
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}


	GLfloat vertices[] =
	{  //     Cordinates      /        Colors       // Texture Cordinates
		-0.5f, -0.5f, 0.0f,      1.0f, 0.0f, 0.0f,    0.0f, 0.0f, //Lower left corner
		-0.5f, 0.5f,  0.0f,       0.0f, 1.0f, 0.0f,   0.0f, 1.0f,   //Upper left corner
		0.5f, 0.5f, 0.0f,        0.0f, 0.6f, 1.0f,    1.0f, 1.0f, //Upper right corner
		0.5f, -0.5f, 0.0f,       1.0f, 1.0f, 1.0f,    1.0f, 0.0f  //Lower right corner
	};

	GLuint indices[] =
	{
		0, 2, 1, //Upper triangle
		0, 3, 2 //Lower triangle

	};

	//Loads the Window

	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 800, 800);

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

	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	//Minecraft Dirt Texture 
	int widthImg, heightImg, numColChr;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load("C:/dev/Voxl-Engine/Images/grass.jpg", &widthImg, &heightImg, &numColChr, 0);


	GLuint texture;
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	
	//Okay so, GL_RGB for .jpgs because they dont have an alpha channel, GL_RGBA for .pngs
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthImg, heightImg, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint tex0Uni = glGetUniformLocation(shaderProgram.ID, "tex0");
	shaderProgram.Activate();
	glUniform1i(tex0Uni, 0);



	//Renders the background color, then applys it to the next frame.

	// glClearColor(0.07f, 0.13f, 0.17f, 1.0f); == Dark Blue, like the tutorial
	glClearColor(0.063f, 0.063f, 0.063f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);



	
	//Main program while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.063f, 0.063f, 0.063f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//Tells OpenGL which shader program to use
		shaderProgram.Activate();
		glUniform1f(uniID, 0.1f);
		glBindTexture(GL_TEXTURE_2D, texture);
		VAO1.Bind();
		//Draws the triangle using the GL Primative, Triangle
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);

		//While window is not closed, allow for input and such.
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	glDeleteTextures(1, &texture);
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}