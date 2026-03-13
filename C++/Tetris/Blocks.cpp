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

	switch (shape)
	{
	case I_shape:
		block.DrawTile(BLUE, SKYBLUE);
		break;

	case O_shape:
		block.DrawTile(GOLD, YELLOW);
		break;

	case T_shape:
		block.DrawTile(VIOLET, PURPLE);
		break;

	case S_shape:
		block.DrawTile(LIME, GREEN);
		break;

	case Z_shape:
		block.DrawTile(MAROON, RED);
		break;

	case L_shape:
		block.DrawTile({255,120,0,255}, YELLOW);
		break;

	case J_shape:
		block.DrawTile(DARKBLUE, BLUE);
		break;
	}

}
