#include "Collisions.h"
#include <iostream>

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
	rad = _size;
}

bool CC::isOverlapped(AABB box, CollisionResults& hit)
{
	Vector2 closestPoint;

	closestPoint.x = std::max(box.pos.x ,std::min(pos.x, (box.pos.x + box.halfSize.x *2)));
	closestPoint.y = std::max(box.pos.y , std::min(box.pos.y + box.halfSize.y*2, pos.y));

	DrawLineV(pos, closestPoint, RED);
	DrawCircleV(box.pos, 5.0f, RED);
	Vector2 aabbToNearest = Vector2Subtract(closestPoint, pos);
	Vector2 AABBdistToCCdist = Vector2Subtract(pos, box.pos);

	
	if (Vector2Length(aabbToNearest) <= (float)rad)
	{
	
		hit.pos = closestPoint;
		hit.collisionDetection = true;
		hit.normal = Vector2Rotate(aabbToNearest, PI);
		hit.normal = Vector2Negate(aabbToNearest);
		hit.normal = Vector2Normalize(hit.normal);
		//std::cout << "AABB to CC dist: " << AABBdistToCCdist.x <<" "<<AABBdistToCCdist.y << std::endl;
		//std::cout << "hit normal Y: " << hit.normal.y << std::endl;

		hit.pDepth = rad - Vector2Length(aabbToNearest);
		std::cout << "Depth is: " << hit.pDepth << std::endl;

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
	DrawCircleLinesV(pos, rad, WHITE);
}
