#pragma once
#include <Engine\MEngine.h>
#include "Cube.h"
#include <soil/SOIL.h>


using namespace Engine;

int main(int argc, char **argv)
{
	MEngine* engine = new MEngine();
	engine->init();

	//local shaders
	engine->getShaderManager()->createProgram("cubeShader",	"Shaders/VertexShader.glsl", "Shaders/FragmentShader.glsl");

	Cube* cube = new Cube();
	Cube* cube2 = new Cube();
	int program = engine->getShaderManager()->getShader("cubeShader");
	if (program != 0)
	{
		cube->setProgram(program);
		cube->create(0,0,0,false);
		cube2->setProgram(program);
		cube2->create(2,0,0,false);
	}
	else
	{
		std::cout << "invalid program...";
		std::cin.get();
	}

	//unsigned int texture = engine->getTextureLoader()->loadTexture("Textures\\Crate.bmp", 256, 256);
	unsigned int texture = SOIL_load_OGL_texture("Textures\\grass.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture2 = SOIL_load_OGL_texture("Textures\\side.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture3 = SOIL_load_OGL_texture("Textures\\dirt.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	cube->setTexture("top", texture);
	cube->setTexture("side", texture2);
	cube->setTexture("bot", texture3);

	cube2->setTexture("top", texture);
	cube2->setTexture("side", texture2);
	cube2->setTexture("bot", texture3);


	//cube->setTexture("Create", texture);
	//cube2->setTexture("Create", texture);

	engine->getModelsManager()->setModel("cube", cube);
	engine->getModelsManager()->setModel("cube2", cube2);
	//glDisable(GL_CULL_FACE);
	engine->run();

	delete engine;
	return 0;
}