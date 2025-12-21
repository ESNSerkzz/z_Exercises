#include "Collisions.h"

AABB::AABB()
{
}

AABB::AABB(Vector2 _pos)
{
	pos = _pos;
	size = { tileSize, tileSize };
	IsOverlapped();
}

bool AABB::IsOverlapped(AABB box)
{
	if (box.pos.x <= pos.x && box.pos.y <= pos.y)
	{
		hit.pos.x = box.pos.x + box.size.x;
		hit.pos.y = box.pos.y + box.size.y;
	}
	if (box.pos.x >= pos.x && box.pos.y >= pos.y)
	{
		hit.pos.x = box.pos.x - box.size.x;
		hit.pos.y = box.pos.y - box.size.y;
	}
	return false;
}
