#include "Blocks.h"

Blocks::Blocks()
{
}

Blocks::Blocks(AABB _box, BlockType _bType)
{
	box = _box;
	shape = _bType;
}