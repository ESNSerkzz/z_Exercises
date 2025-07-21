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

CC::CC(Vector2 _pos, float _size)
{
	pos = _pos;
	size = _size;
}

void CC::Update(Vector2 _pos)
{
	pos = _pos;
}

void CC::Draw()
{
	DrawCircleLinesV(pos, size, RED);
}
