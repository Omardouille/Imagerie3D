#pragma once
#include <Engine\MEngine.h>
#include "Cube.h"
#include <soil/SOIL2.h>
#include "GenerateMap.h"
#include "Goal.h"
#include "Skybox.h"
#include <time.h>
#include <string>

using namespace Engine;

int main(int argc, char **argv)
{
	srand(time(0));
	MEngine* engine = new MEngine("Voxel Game");
	engine->init();

	//shaders
	engine->getShaderManager()->createProgram("cubeShader",	"Shaders\\VertexShader.glsl", "Shaders\\FragmentShader.glsl");
	engine->getShaderManager()->createProgram("skyboxShader", "Shaders\\vertex_shader_skybox.glsl", "Shaders\\fragment_shader_skybox.glsl");
	unsigned int goalT = SOIL_load_OGL_texture("Textures\\Crate.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	int program = engine->getShaderManager()->getShader("cubeShader");
	int skyboxProgram = engine->getShaderManager()->getShader("skyboxShader");
	if (program != 0 && skyboxProgram!=0) {

		//Generation skybox
		Skybox* skybox = new Skybox();
		skybox->setProgram(skyboxProgram);
		engine->getModelsManager()->setModel("skybox", skybox);
		
		//Generation world
		GenerateMap* geneMap = new GenerateMap(program, 4);
		std::vector<Chunk2*> chunks = geneMap->chunks;
		int i = 0;
		for (Chunk2* c : chunks) {
			std::string name = "chunk" + std::to_string(i);
			engine->getModelsManager()->setModel(name, c);
			i++;
		}
		//Generation goal
		Goal* goal = new Goal();
		goal->setProgram(program);
		goal->create(5, 4, 5);
		goal->setTexture("goal", goalT);
		engine->getModelsManager()->setModel("Goal", goal);
		engine->setGoalPosition(goal->getPosition());
		std::cout << "Press Space to jump, ZQSD for move and R to reset position" << std::endl;

		

		engine->run();
	}
	else {
		std::cout << "invalid program...";
		std::cin.get();
	}

	delete engine;
	return 0;
}