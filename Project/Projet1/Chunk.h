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

private:
	// The blocks data
	Block*** m_pBlocks;
};

