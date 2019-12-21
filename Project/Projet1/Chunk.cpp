#include "Chunk.h"


using namespace std;

Chunk::Chunk()
{
	// Create the blocks
	m_pBlocks = new Block**[CHUNK_SIZE];
	for (int i = 0; i < CHUNK_SIZE; i++)
	{
		m_pBlocks[i] = new Block*[CHUNK_SIZE];

		for (int j = 0; j < CHUNK_SIZE; j++)
		{
			m_pBlocks[i][j] = new Block[CHUNK_SIZE];
		}
	}
}


Chunk::~Chunk()
{
	// Delete the blocks
	for (int i = 0; i < CHUNK_SIZE; ++i)
	{
		for (int j = 0; j < CHUNK_SIZE; ++j)
		{
			delete[] m_pBlocks[i][j];
		}

		delete[] m_pBlocks[i];
	}
	delete[] m_pBlocks;
}

void Chunk::generate(int coordX, int coordY, siv::PerlinNoise gen) {

	for (int i = 0; i < CHUNK_SIZE; i++) {
		for (int j = 0; j < CHUNK_SIZE; j++) {
			int megaX = (coordX * CHUNK_SIZE);
			int megaY = (coordY * CHUNK_SIZE);
			int height = (int)(gen.noise(megaX+i,megaY+j)) % CHUNK_SIZE;
			for (int k = 0; k < CHUNK_SIZE; k++) {
				m_pBlocks[i][j][k] = Block();
				if (k < height) m_pBlocks[i][j][k].setBlockType(BlockType::BlockType_Dirt);
				if (k == height) m_pBlocks[i][j][k].setBlockType(BlockType::BlockType_Grass);
			}
		}
	}

}