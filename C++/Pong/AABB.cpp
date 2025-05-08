#include "AABB.h"

void AABB::Draw()
{
	DrawRectangle(pos.x, pos.y, size.x, size.y, DARKPURPLE);
}

void AABB::Draw(Color colour)
{
	DrawRectangleV(pos, size, colour);
}
