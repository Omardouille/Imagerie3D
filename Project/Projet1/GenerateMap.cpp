#include "GenerateMap.h"
#include <soil/SOIL2.h>


GenerateMap::GenerateMap(int program, int size)
{
	unsigned int texture = SOIL_load_OGL_texture("Textures\\grass.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture2 = SOIL_load_OGL_texture("Textures\\dirt.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	unsigned int texture3 = SOIL_load_OGL_texture("Textures\\dirt.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	map = new Map();
	//generere la suite
	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j ++) {
			map->setPosX(i*16);
			map->setPosY(j*16);
			map->genererSuite();
		}
	}
	
	std::map<std::pair<int, int>, Chunk*> allChunks = map->getChunks();
	for (auto const& c : allChunks)
	{
		Chunk* chunk = c.second;
		Chunk2* chunk2 = new Chunk2();
		chunk2->setProgram(program);
		chunk2->create(chunk);
		chunk2->setTexture("top", texture);
		chunk2->setTexture("side", texture2);
		chunk2->setTexture("bot", texture3);
		chunks.push_back(chunk2);
	}
}

GenerateMap::~GenerateMap()
{
}

