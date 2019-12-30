#pragma once
#include "Map.h"
#include "Chunk.h"
#include "Chunk2.h"
class GenerateMap
{
public:
	GenerateMap(int program, int size);
	~GenerateMap();

	Map* map;
	std::vector<Chunk2*> chunks;

};

