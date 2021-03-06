#include "Goal.h"

Goal::Goal()
{
}

Goal::~Goal()
{
}

void Goal::create(int x, int y, int z)
{
	position = glm::vec3(x, y, z);
	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	//time(&timer);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;
	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, //front
									   4, 5, 6, 4, 6, 7, //right
									   8, 9, 10, 8, 10, 11, //back
									   12, 13, 14, 12, 14, 15, //left
									   16, 17, 18, 16, 18, 19, //upper
									   20, 21, 22, 20, 22, 23 }; //bottom

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

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::texture)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
	this->vbos.push_back(ibo);
}

void Goal::draw(const glm::mat4 & projectionMatrix, const glm::mat4 & viewMatrix)
{
	glUseProgram(program);
	glBindVertexArray(vao);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->getTexture("goal"));
	unsigned int textureLocationTop = glGetUniformLocation(program, "texture1");
	glUniform1i(textureLocationTop, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, this->getTexture("goal"));
	unsigned int textureLocationSide = glGetUniformLocation(program, "texture2");
	glUniform1i(textureLocationSide, 1);

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, this->getTexture("goal"));
	unsigned int textureLocationBot = glGetUniformLocation(program, "texture3");
	glUniform1i(textureLocationBot, 2);

	glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &viewMatrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projectionMatrix[0][0]);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

glm::vec3 Goal::getPosition()
{
	return position;
}
