#include "Map.h"
#include <cstdlib>

Map::Map() {

	int seed = rand();

	siv::PerlinNoise gen = siv::PerlinNoise(seed);
	posX = 0;
	posY = 0;
	/*for (int i = -1; i != 1; i++) {
		for (int j = -1; j != 1; j++) {
			m_chunks[{i, j}] = new Chunk();
			m_chunks[{i, j}]->generate(i, j, gen);
		}
	}*/
}

void Map::genererSuite() {
	/*
	for (int i = -1 + posX; i != 1 + posX; i++) {
		for (int j = -1 + posY; j != 1 + posY; j++) {
			m_chunks[{i, j}] = new Chunk();
			m_chunks[{i, j}]->generate(i, j, gen);
		}
	}*/
	m_chunks[{posX, posY}] = new Chunk();
	m_chunks[{posX, posY}]->generate(posX, posY, gen);
}