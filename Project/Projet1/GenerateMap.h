#pragma once
#include "Map.h"
#include "Chunk.h"
#include "ChunkRenderer.h"
#include "Goal.h"
class GenerateMap
{
public:
	GenerateMap(int program, int size);
	~GenerateMap();

	Map* map;
	std::vector<ChunkRenderer*> chunks;
};

