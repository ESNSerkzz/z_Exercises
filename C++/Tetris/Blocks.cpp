#include "Blocks.h"

Blocks::Blocks()
{
}

Blocks::Blocks(AABB _box, BlockType _bType)
{
	box.collision = _box;
	shape = _bType;
	blockSize;
	descentRateTimer = 100;
}

void Blocks::Input()
{
}

void Blocks::Update()
{
}

void Blocks::Draw(Color _colour)
{

}