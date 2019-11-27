#include "Block.h"



Block::Block()
{
	this->m_active = true;
	this->m_blockType = BlockType_Default;
}


Block::~Block()
{
}

void Block::SetActive(bool active) {
	this->m_active = active;
}

bool Block::IsActive() {
	return this->m_active;
}

void Block::setBlockType(BlockType bt) {
	this->m_blockType = bt;
}