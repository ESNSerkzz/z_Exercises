#include "Blocks.h"

Blocks::Blocks()
{
}

Blocks::Blocks(AABB _box, BlockType _bType)
{
	block.collision = _box;
	shape = _bType;
	descentRateTimer = 100;
}

void Blocks::Input()
{

}

void Blocks::Update()
{

}

void Blocks::Draw()
{

}
