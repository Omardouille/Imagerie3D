#include "Chunk2.h"



Chunk2::Chunk2()
{
	
}


Chunk2::~Chunk2()
{
}

void Chunk2::create(int taille, MEngine* engine) {
	this->taille = taille;
	unsigned int texture = SOIL_load_OGL_texture("Textures\\grass.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture2 = SOIL_load_OGL_texture("Textures\\side.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture3 = SOIL_load_OGL_texture("Textures\\dirt.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	std::vector<unsigned int> indices;
	int k = 0;
	for (int i = 0; i < taille; i++) {
		for (int j = 0; j < taille; j++) {
			//for (int k = 0; k < taille; k++) {
			Cube2* cube = new Cube2();
			//cube->setProgram(program);
			if (i > 0 && i < taille - 1) {
				if (j > 0 && j < taille - 1) {
					cube->create(i * 2, 0, j * 2, false, false, false, false, false, true, false);
				}
				else {
					cube->create(i * 2, 0, j * 2, false, true, true, true, true, true, false);
				}
			}
			else {
				cube->create(i * 2, 0, j * 2, false, true, true, true, true, true, false);
			}
			//cube->create(i * 2, 0, j * 2, false, true);
			//cube->setTexture("top", texture);
			//cube->setTexture("side", texture2);
			//cube->setTexture("bot", texture3);
			//std::string name = "cube" + std::to_string(i) + "," + std::to_string(j);
			//engine->getModelsManager()->setModel(name, cube);
			//this->listCubes.push_back(cube);
			//}

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

void Chunk2::draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix)
{
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

	glDrawElements(GL_TRIANGLES, 36*taille*taille, GL_UNSIGNED_INT, 0);
}