#include "Cube2.h"
using namespace Engine;
using namespace Rendering;
using namespace Models;

#define PI 3.14159265

Cube2::Cube2()
{
}

Cube2::~Cube2()
{
}

void Cube2::create(float x, float y, float z, bool b)
{
	oneTexture = b;
	position = glm::vec3(x, y, z);

	time(&timer);

	/*std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, //front
									   4, 5, 6, 4, 6, 7, //right
									   8, 9, 10, 8, 10, 11, //back
									   12, 13, 14, 12, 14, 15, //left
									   16, 17, 18, 16, 18, 19, //upper
									   20, 21, 22, 20, 22, 23 }; //bottom*/

	//front
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(0, 0)));

	//right
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(0, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(0, 1)));

	//back
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(0, 0)));

	//left
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(1, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(1, 0)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(0, 0)));


	//upper
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(2, 2)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, 1.0 + z), glm::vec2(3, 2)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(3, 3)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, 1.0 + y, -1.0 + z), glm::vec2(2, 3)));


	////bottom
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(4, 4)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, -1.0 + z), glm::vec2(5, 4)));
	vertices.push_back(VertexFormat(glm::vec3(1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(5, 5)));
	vertices.push_back(VertexFormat(glm::vec3(-1.0 + x, -1.0 + y, 1.0 + z), glm::vec2(4, 5)));

	rotation_speed = glm::vec3(0.0, 0.0, 0.0);
	rotation = glm::vec3(0.0, 0.0, 0.0);

}

void Cube2::create(float x, float y, float z, bool b, bool front, bool right, bool back, bool left, bool up, bool bot)
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

	rotation_speed = glm::vec3(0.0, 0.0, 0.0);
	rotation = glm::vec3(0.0, 0.0, 0.0);

}
/**
void Cube2::update()
{
	rotation = 0.01f * rotation_speed + rotation;
	rotation_sin = glm::vec3(rotation.x * PI / 180, rotation.y * PI / 180, rotation.z * PI / 180);
}*/
/*
void Cube2::draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{

	if (oneTexture) {

		glUseProgram(program);
		glBindVertexArray(vao);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->getTexture("Create"));
		unsigned int textureLocation = glGetUniformLocation(program, "texture1");
		glUniform1i(textureLocation, 0);

		glUniform3f(glGetUniformLocation(program, "rotation"), rotation_sin.x, rotation_sin.y, rotation_sin.z);
		glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &viewMatrix[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projectionMatrix[0][0]);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	}
	else {
		glUseProgram(program);
		glBindVertexArray(vao);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->getTexture("side"));
		unsigned int textureLocationTop = glGetUniformLocation(program, "texture1");
		glUniform1i(textureLocationTop, 0);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, this->getTexture("top"));
		unsigned int textureLocationSide = glGetUniformLocation(program, "texture2");
		glUniform1i(textureLocationSide, 1);

		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, this->getTexture("bot"));
		unsigned int textureLocationBot = glGetUniformLocation(program, "texture3");
		glUniform1i(textureLocationBot, 2);

		glUniform3f(glGetUniformLocation(program, "rotation"), rotation_sin.x, rotation_sin.y, rotation_sin.z);
		glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &viewMatrix[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projectionMatrix[0][0]);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	}
}*/