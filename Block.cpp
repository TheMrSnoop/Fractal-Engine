#include "Block.h"
#include "Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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


VBO VBO1(vertices, sizeof(vertices));
EBO EBO1(indices, sizeof(indices));

Block::Block(BlockType type, Texture blockTexture, float blockDurability, glm::vec3 Position, Shader shaderProgram)
{
	blockTexture.Bind();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, Position);
	shaderProgram.setMat4("model", model);

	glDrawElements(GL_TRIANGLES, EBO1.ID, GL_UNSIGNED_INT, 0);

}
