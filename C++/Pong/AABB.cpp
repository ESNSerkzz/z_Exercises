#include "AABB.h"

void AABB::Draw()
{
	DrawRectangleLines(pos.x, pos.y, size.x, size.y, GREEN);
}
