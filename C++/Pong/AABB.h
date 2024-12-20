#pragma once
#include <raylib.h>
#include "Ball.h"
#include "Paddles.h"

enum DirectionalPlacement
{
	//which direction it is placed in relation to another box (collision)

	above, bellow, l_side, r_side
};

class AABB
{
public:
	Vector2 pos;
	Vector2 size;

	AABB();
	AABB(Vector2 centre, Vector2 _Size) : pos(centre), size(_Size) {};

	void setPos(Vector2 _pos) { pos = _pos; };

	bool isOverLapped(AABB box) 
	{
		return(
			pos.x < box.pos.x + box.size.x &&
			pos.x + size.x > box.pos.x &&
			pos.y < box.pos.y + box.size.y &&
			pos.y + size.y > box.pos.y
			);
	};
	bool isOverLapped(Vector2 point)
	{
		
		return (
			point.x > pos.x &&
			point.x < pos.x + size.x &&
			point.y > pos.y &&
			point.y < pos.y + size.y
			);
	}

	bool OverLappedBounce(AABB _ballCollision, AABB _paddleBoxCollision)
	{
		
	}
};

