#include "Collisions.h"

Direction AABB::GetDir(AABB box)
{
	float DisX = fabsf(pos.x - box.pos.x);
	float DisY = fabsf(pos.y - box.pos.y);
	if (DisX > DisY)
	{
		if (pos.x < box.pos.x)
		{
			return Right;
		}
		if (pos.x > box.pos.x)
		{
			return Left;
		}

	}
	else
	{
		if (pos.y < box.pos.y)
		{
			return Down;
		}
		if (pos.y > box.pos.y)
		{
			return Up;
		}
	}

}

void AABB::Draw()
{
	DrawRectangleLines(pos.x, pos.y, halfSize.x * 2, halfSize.y * 2, PURPLE);
}

CC::CC()
{
}

CC::CC(Vector2 _pos, float _size)
{
	pos = _pos;
	size = _size;
}

bool CC::isOverlapped(AABB box, CollisionResults hit)
{
	Vector2 closestPoint;

	closestPoint.x = std::max(box.pos.x, std::min(pos.x, (box.pos.x + box.halfSize.x)));
	closestPoint.y = std::max(box.pos.y, std::min(box.pos.y + box.halfSize.y, pos.y));

	//DrawLineV(pos, closestPoint, YELLOW);

	Vector2 aabbToNearest = Vector2Subtract(closestPoint, pos);
	Vector2 AABBdistToCCdist = Vector2Subtract(pos, box.pos);



	if (Vector2Length(aabbToNearest) <= (float)size)
	{
		
		hit.pos = pos;
		hit.collisionDetection = true;
		hit.normal = Vector2Rotate(aabbToNearest, PI);
		hit.normal = Vector2Negate(aabbToNearest);
		hit.normal = Vector2Normalize(hit.normal);
		//std::cout << hit.normal.x << std::endl;
		//std::cout << hit.normal.y << std::endl;

		hit.pDepth = size - Vector2Length(aabbToNearest);
		
		return true;
	}
	return false;
}

void CC::Update(Vector2 _pos)
{
	pos = _pos;
}

void CC::Draw()
{
	DrawCircleLinesV(pos, size, RED);
}
