#include "Collisions.h"

CC::CC()
{
	pos = { 0, 0 };
	rad = 5.0f;
}

CC::CC(Vector2 _pos, float _rad)
{
	pos = _pos;
	rad = _rad;
}

bool CC::isOverlapped(AABB box)
{
	Vector2 closetPoint;

	closetPoint.x = std::max(box.pos.x, std::min(pos.x, (box.pos.x + box.size.x) ));
	closetPoint.y = std::max(box.pos.y, std::min(box.pos.y + box.size.y, pos.y));

	DrawLineV(pos, closetPoint, YELLOW);
	
	Vector2 aabbToNearest = Vector2Subtract(closetPoint, pos);
	Vector2 AABBdistToCCdist = Vector2Subtract(pos, box.pos);



	return Vector2Length(aabbToNearest) < rad;
}

AABB::AABB()
{
	pos = { 0,0 };
	size = { 0, 0 };
}

AABB::AABB(Vector2 _pos, Vector2 _size)
{
	pos = _pos;
	size = _size;
}

bool AABB::isOverlapped(AABB box)
{
	return(
		pos.x < box.pos.x + box.size.x &&
		pos.x + size.x > box.pos.x &&
		pos.y < box.pos.y + box.size.y &&
		pos.y + size.y > box.pos.y
		);
}

void AABB::Draw()
{
	DrawRectangleLines(pos.x, pos.y, size.x, size.y, RED);
}
