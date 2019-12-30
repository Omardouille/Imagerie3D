#include "Chunk.h"


using namespace std;

Chunk::Chunk()
{
	// Create the blocks
	
	/*m_pBlocks = new Block**[CHUNK_SIZE];
	for (int i = 0; i < CHUNK_SIZE; i++)
	{
		m_pBlocks[i] = new Block*[CHUNK_SIZE];

		for (int j = 0; j < CHUNK_SIZE; j++)
		{
			m_pBlocks[i][j] = new Block[CHUNK_SIZE];
			
		}
	}*/
	
	heightMap = new int*[CHUNK_SIZE];
	for (int i = 0; i < CHUNK_SIZE; i++) {
		heightMap[i] = new int[CHUNK_SIZE];
	}
}


Chunk::~Chunk()
{
	// Delete the blocks
	/*for (int i = 0; i < CHUNK_SIZE; ++i)
	{
		for (int j = 0; j < CHUNK_SIZE; ++j)
		{
			delete[] m_pBlocks[i][j];
		}

		delete[] m_pBlocks[i];
	}
	delete[] m_pBlocks;*/

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
			/*
			for (int k = 0; k < CHUNK_SIZE; k++) {
				m_pBlocks[i][j][k] = Block();
				if (k < height) m_pBlocks[i][j][k].setBlockType(BlockType::BlockType_Dirt);
				if (k == height) m_pBlocks[i][j][k].setBlockType(BlockType::BlockType_Grass);
			}*/
		}
	}

}

