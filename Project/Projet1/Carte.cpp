#include "Carte.h"
#include <cstdlib>

Carte::Carte() {

	int seed = rand();

	siv::PerlinNoise gen = siv::PerlinNoise(seed);
	posX = 0;
	posY = 0;
	for (int i = -1; i != 1; i++) {
		for (int j = -1; j != 1; j++) {
			m_chunks[{i, j}] = Chunk();
			m_chunks[{i, j}].generate(i,j,gen);
		}
	}

}

void Carte::genererSuite() {

	for (int i = -1+posX; i != 1 + posX; i++) {
		for (int j = -1 + posY; j != 1 + posY; j++) {
			m_chunks[{i, j}] = Chunk();
			m_chunks[{i, j}].generate(i, j, gen);
		}
	}

}