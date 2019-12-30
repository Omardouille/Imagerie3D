#include "Chunk2.h"



Chunk2::Chunk2()
{
	active = true;
}


Chunk2::~Chunk2()
{
}

void Chunk2::create(int taille,int x,int y, int z) {
	this->position = glm::vec3(x, y, z);
	this->taille = taille;
	std::vector<unsigned int> indices;
	int k = 0;
	for (int i = x; i < taille + x; i++) {
		for (int j = z; j < taille + z; j++) {
			if (i > (taille + x) / 2)
				y-=2;
			world.push_back(glm::vec3(i*2, y, j*2));
			//for (int k = 0; k < taille; k++) {
			Cube2* cube = new Cube2();
			//cube->setProgram(program);
			/*
			if (i > x && i < taille + x - 1) {
				if (j > z && j < taille + z - 1) {
					cube->create(i * 2, y, j * 2, false, false, false, false, false, true, false);
				}
				else {
					cube->create(i * 2, y, j * 2, false, true, true, true, true, true, false);
				}
			}
			else {
				cube->create(i * 2, y, j * 2, false, true, true, true, true, true, false);
			}*/
			cube->create(i * 2, y, j * 2,false,true);
			this->vertices.insert(std::end(this->vertices), std::begin(cube->vertices), std::end(cube->vertices));
			int tmp = k;
			k++;
			indices.push_back(0 + tmp * 24);
			indices.push_back(1 + tmp * 24);
			indices.push_back(2 + tmp * 24);
			indices.push_back(0 + tmp * 24);
			indices.push_back(2 + tmp * 24);
			indices.push_back(3 + tmp * 24);
			indices.push_back(4 + tmp * 24);
			indices.push_back(5 + tmp * 24);
			indices.push_back(6 + tmp * 24);
			indices.push_back(4 + tmp * 24);
			indices.push_back(6 + tmp * 24);
			indices.push_back(7 + tmp * 24);
			indices.push_back(8 + tmp * 24);
			indices.push_back(9 + tmp * 24);
			indices.push_back(10 + tmp * 24);
			indices.push_back(8 + tmp * 24);
			indices.push_back(10 + tmp * 24);
			indices.push_back(11 + tmp * 24);
			indices.push_back(12 + tmp * 24);
			indices.push_back(13 + tmp * 24);
			indices.push_back(14 + tmp * 24);
			indices.push_back(12 + tmp * 24);
			indices.push_back(14 + tmp * 24);
			indices.push_back(15 + tmp * 24);
			indices.push_back(16 + tmp * 24);
			indices.push_back(17 + tmp * 24);
			indices.push_back(18 + tmp * 24);
			indices.push_back(16 + tmp * 24);
			indices.push_back(18 + tmp * 24);
			indices.push_back(19 + tmp * 24);
			indices.push_back(20 + tmp * 24);
			indices.push_back(21 + tmp * 24);
			indices.push_back(22 + tmp * 24);
			indices.push_back(20 + tmp * 24);
			indices.push_back(22 + tmp * 24);
			indices.push_back(23 + tmp * 24);
		}
		
	}

	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

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

void Chunk2::create(Chunk* chunk)
{
	this->position = glm::vec3(chunk->getX(),0, chunk->getY());
	this->taille = 16;
	int** heightMap = chunk->getHeightMap();
	std::vector<unsigned int> indices;
	int k = 0;
	for (int i = position.x; i < taille + position.x; i++) {
		for (int j = position.z; j < taille + position.z; j++) {
			int x = i - position.x;
			int z = j - position.z;
			int y = heightMap[x][z];
			for (int l = 0; l < taille; l++) {
				int newY = y - l;
				world.push_back(glm::vec3(i * 2, newY*2, j * 2));
				//for (int k = 0; k < taille; k++) {
				Cube2* cube = new Cube2();
				cube->create(i * 2, newY*2, j * 2, false, true);
				this->vertices.insert(std::end(this->vertices), std::begin(cube->vertices), std::end(cube->vertices));
				int tmp = k;
				k++;
				indices.push_back(0 + tmp * 24);
				indices.push_back(1 + tmp * 24);
				indices.push_back(2 + tmp * 24);
				indices.push_back(0 + tmp * 24);
				indices.push_back(2 + tmp * 24);
				indices.push_back(3 + tmp * 24);
				indices.push_back(4 + tmp * 24);
				indices.push_back(5 + tmp * 24);
				indices.push_back(6 + tmp * 24);
				indices.push_back(4 + tmp * 24);
				indices.push_back(6 + tmp * 24);
				indices.push_back(7 + tmp * 24);
				indices.push_back(8 + tmp * 24);
				indices.push_back(9 + tmp * 24);
				indices.push_back(10 + tmp * 24);
				indices.push_back(8 + tmp * 24);
				indices.push_back(10 + tmp * 24);
				indices.push_back(11 + tmp * 24);
				indices.push_back(12 + tmp * 24);
				indices.push_back(13 + tmp * 24);
				indices.push_back(14 + tmp * 24);
				indices.push_back(12 + tmp * 24);
				indices.push_back(14 + tmp * 24);
				indices.push_back(15 + tmp * 24);
				indices.push_back(16 + tmp * 24);
				indices.push_back(17 + tmp * 24);
				indices.push_back(18 + tmp * 24);
				indices.push_back(16 + tmp * 24);
				indices.push_back(18 + tmp * 24);
				indices.push_back(19 + tmp * 24);
				indices.push_back(20 + tmp * 24);
				indices.push_back(21 + tmp * 24);
				indices.push_back(22 + tmp * 24);
				indices.push_back(20 + tmp * 24);
				indices.push_back(22 + tmp * 24);
				indices.push_back(23 + tmp * 24);
			}
		}

	}



	GLuint vao;
	GLuint vbo;
	GLuint ibo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

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

void Chunk2::draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{
	if (active) {
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

		//glUniform3f(glGetUniformLocation(program, "rotation"), rotation_sin.x, rotation_sin.y, rotation_sin.z);
		glUniformMatrix4fv(glGetUniformLocation(program, "view_matrix"), 1, false, &viewMatrix[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(program, "projection_matrix"), 1, false, &projectionMatrix[0][0]);

		glDrawElements(GL_TRIANGLES, 36 * taille*taille*taille, GL_UNSIGNED_INT, 0);
	}
}

std::vector<glm::vec3> Chunk2::getWorld()
{
	return world;
}
