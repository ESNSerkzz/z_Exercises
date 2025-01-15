#include "AABB.h"

AABB::AABB()
{
}

AABB::AABB(Rect rectangle)
{
	box = rectangle;
}

//AABB::AABB(RayLine ray)
//{
//	line = ray;
//}

void AABB::Draw(Color c)
{
	DrawRectangleV(box.pos, box.size, c);
	

}

void AABB::UpdatePos(Vector2 newPos)
{
	box.pos = newPos;
	
}
