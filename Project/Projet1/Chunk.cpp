#include "Chunk.h"


using namespace std;

Chunk::Chunk()
{	
	heightMap = new int*[CHUNK_SIZE];
	for (int i = 0; i < CHUNK_SIZE; i++) {
		heightMap[i] = new int[CHUNK_SIZE];
	}
}


Chunk::~Chunk()
{
	for (int i = 0; i < CHUNK_SIZE; ++i)
	{
		delete[] heightMap[i];
	}
	delete[] heightMap;
}


void Chunk::generate(int coordX, int coordY, siv::PerlinNoise gen) {
	x = coordX;
	y = coordY;
	for (int i = 0; i < CHUNK_SIZE; i++) {
		for (int j = 0; j < CHUNK_SIZE; j++) {
			float height = gen.noise(i + x + 0.5, j + y + 0.5);
			float heightNormalized = height * CHUNK_SIZE/2;
			heightMap[i][j] = heightNormalized;
		}
	}

}

