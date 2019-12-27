#pragma once
#include <Engine\MEngine.h>
#include "Cube.h"
#include <soil/SOIL2.h>
#include "Chunk2.h"
#include "Goal.h"


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
	unsigned int goalT = SOIL_load_OGL_texture("Textures\\Crate.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

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

	Goal* goal = new Goal();
	goal->setProgram(program);
	goal->create(5,4,5);
	goal->setTexture("goal", goalT);
	engine->getModelsManager()->setModel("Goal", goal);
	engine->setGoalPosition(goal->getPosition());


	glDisable(GL_CULL_FACE);
	engine->run();

	delete engine;
	return 0;
}