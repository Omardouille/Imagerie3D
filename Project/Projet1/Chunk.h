#pragma once
#include "PerlinNoise.hpp"
class Chunk
{
public:
	Chunk();
	~Chunk();

	void generate(int coordX, int coordY, siv::PerlinNoise gen);

	static const int CHUNK_SIZE = 16;

	int getX() { return x; }
	int getY() { return y; }
	int** getHeightMap() { return heightMap; }

private:
	int** heightMap;

	int x, y;
};