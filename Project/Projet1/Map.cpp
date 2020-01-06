#include "Map.h"
#include <cstdlib>

Map::Map() {

	int seed = rand();

	siv::PerlinNoise gen = siv::PerlinNoise(seed);
	posX = 0;
	posY = 0;
}

void Map::genererSuite() {
	m_chunks[{posX, posY}] = new Chunk();
	m_chunks[{posX, posY}]->generate(posX, posY, gen);
}