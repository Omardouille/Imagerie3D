#pragma once

#include <map>
#include "Chunk.h"
#include "PerlinNoise.hpp"

class Carte
{

public :
	Carte();
	void genererSuite();
	void setPosX(int newPos) { posX = newPos; }
	void setPosY(int newPos) { posY = newPos; }

protected:
	std::map<std::pair<int, int>, Chunk> m_chunks;
	int posX;
	int posY;
	siv::PerlinNoise gen;

};

