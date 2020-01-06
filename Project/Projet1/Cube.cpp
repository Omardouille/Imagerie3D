#include "Cube.h"
using namespace Engine;
using namespace Rendering;
using namespace Models;

Cube::Cube()
{
}

Cube::~Cube()
{
}

void Cube::create(float x, float y, float z, bool b, bool front, bool right, bool back, bool left, bool up, bool bot)
{
	oneTexture = b;
	position = glm::vec3(x, y, z);

	time(&timer);

	//front
	if (front) {
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(0, 1)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(1, 1)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(1, 0)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(0, 0)));
	}
	//right
	if (right) {
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(0, 0)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(1, 0)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(1, 1)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(0, 1)));
	}
	//back
	if (back) {
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(0, 1)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(1, 1)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(1, 0)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(0, 0)));
	}
	//left
	if (left) {
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(0, 1)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(1, 1)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(1, 0)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(0, 0)));
	}

	//upper
	if (up) {
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(2, 2)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(3, 2)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(3, 3)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(2, 3)));
	}

	////bottom
	if (bot) {
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(4, 4)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(5, 4)));
		vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(5, 5)));
		vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(4, 5)));
	}


}