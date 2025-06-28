#include "Block.h"
#include "Texture.h"
#include"shaderClass.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Block::Block(BlockType type, Texture blockTexture, float blockDurability, glm::vec3 Position, GLuint indices, int indexCount, Shader shaderProgram)
{
	blockTexture.Bind();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, Position);
	shaderProgram.setMat4("model", model);

	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

}
