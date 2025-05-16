#include "BrickTiles.h"

BrickTiles::BrickTiles()
{
}

BrickTiles::BrickTiles(Vector2 _pos, Vector2 _size)
{
	dataInfo.pos = _pos;
	dataInfo.size = _size;

	BrickCollision = AABB(_pos, _size);
	deletable = false;
}

void BrickTiles::Draw()
{
	DrawRectangleV(dataInfo.pos, dataInfo.size, PURPLE);
}
