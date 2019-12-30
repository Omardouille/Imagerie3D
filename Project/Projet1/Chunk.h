#pragma once
#include "Block.h"
#include "PerlinNoise.hpp"
class Chunk
{
public:
	Chunk();
	~Chunk();

	void Update(float dt);

	void generate(int coordX, int coordY, siv::PerlinNoise gen);

	//void Render(OpenGLRenderer* pRenderer);

	static const int CHUNK_SIZE = 16;

	//Block*** getBlocks() { return m_pBlocks; }
	int getX() { return x; }
	int getY() { return y; }
	int** getHeightMap() { return heightMap; }

private:
	// The blocks data
	//Block*** m_pBlocks;
	int** heightMap;

	int x, y;
};