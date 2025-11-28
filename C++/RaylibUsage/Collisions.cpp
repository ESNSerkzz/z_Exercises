#include "Collisions.h"
#include <iostream>

Direction AABB::GetDir(AABB box)
{
	float DisX = fabsf(pos.x - box.pos.x);
	float DisY = fabsf(pos.y - box.pos.y);
	if (DisX > DisY)
	{
		//box.pos is on the right side of (pos)
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
bool AABB::isOverlapped(AABB box, CollisionResults& hit)
{
	if (overlaps(box))
	{
		
		if (box.pos.x <= pos.x && box.pos.y <= pos.y)
		{
			hit.pos.x = box.pos.x + box.halfSize.x;
			hit.pos.y = box.pos.y + box.halfSize.y;
		}
		if (box.pos.x >= pos.x && box.pos.y >= pos.y)
		{
			hit.pos.x = box.pos.x - box.halfSize.x;
			hit.pos.y = box.pos.y - box.halfSize.y;
		}
		//min (pos.x, box.pos.x + box.halfsize.x)
		//max =  (pos. x + pos.size )

		/*if (box.pos.x <= pos.x)
		{
			hit.pos.x = box.pos.x + box.halfSize.x;
		}
		if (box.pos.x >= pos.x)
		{
			hit.pos.x = box.pos.x - box.halfSize.x;
		}

		if (box.pos.y <= pos.y)
		{
			hit.pos.y = box.pos.y + box.halfSize.y;
		}
		if (box.pos.y >= pos.y)
		{
			hit.pos.y = box.pos.y - box.halfSize.y;
		}*/
		//TODO
		//get the hitcollision accurate.



	}
	return true;
}
void AABB::Draw()
{
	DrawRectangleLines(pos.x, pos.y, halfSize.x * 2, halfSize.y * 2, PURPLE);
}

void AABB::Draw(Color _color)
{
	DrawRectangleLines(pos.x, pos.y, halfSize.x * 2, halfSize.y * 2, _color);
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

	closestPoint.x = std::max(float (box.pos.x) ,std::min(pos.x, float (box.pos.x + box.halfSize.x *2)));
	closestPoint.y = std::max(float (box.pos.y) ,std::min( float (box.pos.y + box.halfSize.y*2), pos.y));

	DrawLineV(pos, closestPoint, RED);
	//DrawCircleV(box.pos, 5.0f, RED);
	Vector2 aabbToNearest = Vector2Subtract(closestPoint, pos);
	Vector2 AABBdistToCCdist = Vector2Subtract(pos, Vector2Add(box.pos, box.halfSize));

	if (Vector2Length(aabbToNearest) <= (float)rad)
	{
	
		hit.pos = closestPoint;
		hit.collisionDetection = true;
		if (fabs(AABBdistToCCdist.x) > fabs(AABBdistToCCdist.y))
		{
			if (AABBdistToCCdist.x < 0)
			{
				hit.normal = { -1, 0 };
			}
			else
			{
				hit.normal = { 1,0 };
			}
		}
		else
		{
			if (AABBdistToCCdist.y > 0)
			{
				hit.normal = { 0, 1 };
			}
			else
			{
				hit.normal = { 0, -1 };
			}
		}

		/*hit.normal = Vector2Rotate(aabbToNearest, PI);
		hit.normal = Vector2Negate(aabbToNearest);
		hit.normal = Vector2Normalize(hit.normal);*/

		if (pos.y < box.pos.y) 
		{
			/*std::cout << "normal X: " << hit.normal.x << std::endl;
			std::cout << "normal Y: " << hit.normal.y << std::endl;*/

			//hit.normal.y = -1;
		}
		//std::cout << "AABB to CC dist: " << AABBdistToCCdist.x <<" "<<AABBdistToCCdist.y << std::endl;
		//std::cout << "hit normal Y: " << hit.normal.y << std::endl;

		hit.pDepth = rad - Vector2Length(aabbToNearest);
		
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
	DrawCircleLinesV(pos, rad, RED);
}

void CC::Draw(Color _color)
{
	DrawCircleLinesV(pos, rad, _color);
}
