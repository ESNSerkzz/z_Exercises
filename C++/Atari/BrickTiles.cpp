#include "BrickTiles.h"

BrickTiles::BrickTiles()
{
}

BrickTiles::BrickTiles(Vector2 _pos, Vector2 _size)
{
	dataInfo.pos = _pos;
	dataInfo.size = _size;

	Bricks = AABB(_pos, _size);
}


void BrickTiles::Draw()
{
	DrawRectangleV(dataInfo.pos, dataInfo.size, PURPLE);
}
