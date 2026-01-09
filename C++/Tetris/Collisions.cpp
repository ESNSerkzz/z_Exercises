#include "Collisions.h"

AABB::AABB()
{

}

AABB::AABB(Vector2 _pos)
{
	pos = _pos;
	size = { tileSize, tileSize };
}

bool AABB::IsOverlapped(AABB box)
{
	if (box.pos.x <= pos.x && box.pos.y <= pos.y)
	{
		pos.x = box.pos.x + box.size.x;
		pos.y = box.pos.y + box.size.y;
	}
	if (box.pos.x >= pos.x && box.pos.y >= pos.y)
	{
		pos.x = box.pos.x - box.size.x;
		pos.y = box.pos.y - box.size.y;
	}
	return true;
}

void AABB::DrawAABB(Color _FillColour)
{
	DrawRectangleV(pos, size, LIGHTGRAY);
	DrawRectangleLines(pos.x, pos.y, size.x, size.y, DARKGRAY);
}
