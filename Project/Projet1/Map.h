#pragma once

#include <map>
#include "Chunk.h"
#include "PerlinNoise.hpp"

class Map
{

public:
	Map();
	void genererSuite();
	void setPosX(int newPos) { posX = newPos; }
	void setPosY(int newPos) { posY = newPos; }
	std::map<std::pair<int, int>, Chunk*> getChunks() { return m_chunks; }
protected:
	std::map<std::pair<int, int>, Chunk*> m_chunks;
	int posX;
	int posY;
	siv::PerlinNoise gen;

};