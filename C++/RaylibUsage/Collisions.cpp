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