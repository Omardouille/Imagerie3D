#pragma once
#include <Engine\MEngine.h>
#include "Cube.h"
#include <soil/SOIL2.h>
#include "Chunk2.h"


using namespace Engine;

int main(int argc, char **argv)
{
	MEngine* engine = new MEngine();
	engine->init();

	//local shaders
	engine->getShaderManager()->createProgram("cubeShader",	"Shaders\\VertexShader.glsl", "Shaders\\FragmentShader.glsl");
	unsigned int texture = SOIL_load_OGL_texture("Textures\\grass.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture2 = SOIL_load_OGL_texture("Textures\\side.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture3 = SOIL_load_OGL_texture("Textures\\dirt.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	//Cube* cube = new Cube();
	//Cube* cube2 = new Cube();
	int program = engine->getShaderManager()->getShader("cubeShader");
	Chunk2* chunk = new Chunk2();
	chunk->setProgram(program);
	chunk->create(16);
	chunk->setTexture("top", texture);
	chunk->setTexture("side", texture2);
	chunk->setTexture("bot", texture3);
	
	engine->getModelsManager()->setModel("chunk", chunk);

	Chunk2* chunk2 = new Chunk2();
	chunk2->setProgram(program);
	chunk2->create(16,0,2,16);
	chunk2->setTexture("top", texture);
	chunk2->setTexture("side", texture2);
	chunk2->setTexture("bot", texture3);
	engine->getModelsManager()->setModel("chunk2", chunk2);

	std::vector<glm::vec3> worlds = chunk->getWorld();
	for(int i=0;i< chunk2->getWorld().size();i++)
		worlds.push_back(chunk2->getWorld()[i]);
	engine->setWorld(worlds);



	
	
	/*
	if (program != 0)
	{
		int taille = 32;
		for (int i = 0; i < taille; i++) {
			for (int j = 0; j < taille; j++) {
				//for (int k = 0; k < taille; k++) {
					Cube* cube = new Cube();
					cube->setProgram(program);
					if (i > 0 && i < taille-1) {
						if (j > 0 && j < taille-1) {
							cube->create(i * 2, 0, j * 2, false, false, false, false, false, true, false);
						}
						else {
							cube->create(i * 2, 0, j * 2, false, true, true, true, true, true,false);
						}
					}
					else {
						cube->create(i * 2, 0, j * 2, false, true, true, true, true, true, false);
					}
					cube->setTexture("top", texture);
					cube->setTexture("side", texture2);
					cube->setTexture("bot", texture3);
					std::string name = "cube" + std::to_string(i) + "," + std::to_string(j);
					engine->getModelsManager()->setModel(name, cube);
				//}

			}
		}
		/*cube->setProgram(program);
		cube->create(0,0,0,false);
		cube2->setProgram(program);
		cube2->create(2,0,0,false);
	}
	else
	{
		std::cout << "invalid program...";
		std::cin.get();
	}*/

	//unsigned int texture = engine->getTextureLoader()->loadTexture("Textures\\Crate.bmp", 256, 256);
	

	/*
	cube->setTexture("top", texture);
	cube->setTexture("side", texture2);
	cube->setTexture("bot", texture3);

	cube2->setTexture("top", texture);
	cube2->setTexture("side", texture2);
	cube2->setTexture("bot", texture3);
	*/

	//cube->setTexture("Create", texture);
	//cube2->setTexture("Create", texture);

	//engine->getModelsManager()->setModel("cube", cube);
	//engine->getModelsManager()->setModel("cube2", cube2);

	glDisable(GL_CULL_FACE);
	engine->run();

	delete engine;
	return 0;
}