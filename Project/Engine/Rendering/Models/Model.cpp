#include "Model.h"
using namespace Engine;
using namespace Rendering;
using namespace Models;

Model::Model() 
{
}

Model::~Model()
{
	destroy();
}

void Model::draw()
{
}

void Model::draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{

}

void Model::update()
{
}

void Model::setProgram(GLuint program)
{
	if (program == 0) return;
	this->program = program;
}

GLuint Model::getVao() const
{
	return vao;
}

const std::vector<GLuint>& Model::getVbos() const
{
	return vbos;
}

void Model::destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();

	if (textures.size() > 0)
	{
		for (auto t : textures)
		{
			glDeleteTextures(1, &t.second);
		}
		textures.clear();
	}
}

const GLuint Model::getTexture(std::string textureName) const
{
	return textures.at(textureName);
}

void Model::setTexture(std::string textureName, GLuint texture)
{
	if (texture == 0) return;
	textures[textureName] = texture;
}