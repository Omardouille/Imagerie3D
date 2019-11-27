#pragma once
#include "BlockType.h"

class Block
{
public:
	Block();
	~Block();

	bool IsActive();
	void SetActive(bool active);
	void setBlockType(BlockType bt);
private:
	bool m_active;

	BlockType m_blockType;
};

