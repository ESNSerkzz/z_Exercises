#include "Collisions.h"
#include "iostream"

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

bool CC::isOverlapped(AABB box, hitResult& hit)
{
	Vector2 closestPoint;

	closestPoint.x = std::max(box.pos.x, std::min(pos.x, (box.pos.x + box.size.x)));
	closestPoint.y = std::max(box.pos.y, std::min(box.pos.y + box.size.y, pos.y));

	DrawLineV(pos, closestPoint, YELLOW);

	Vector2 aabbToNearest = Vector2Subtract(closestPoint, pos);
	Vector2 AABBdistToCCdist = Vector2Subtract(pos, box.pos);


	if (Vector2Length(aabbToNearest) < rad)
	{
		//figure out the where the angle of the ball is in relation to the AABB (player)
		hit.position = pos;
		hit.collided = true;
		//hit.normal = Vector2Rotate(aabbToNearest, PI);
		hit.normal = Vector2Negate(aabbToNearest);
		hit.normal = Vector2Normalize(hit.normal);
		std::cout << hit.normal.x << std::endl;
		std::cout << hit.normal.y << std::endl;

		//if ()


		return true;
	}

	return false;
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

bool AABB::isOverlapped(AABB box, hitResult& hit)
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
