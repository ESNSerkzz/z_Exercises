#pragma once
#include <raylib.h>

class AABB
{
public:
	Vector2 pos;
	Vector2 size;

	AABB() {};
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


	//depenetrate the ball from the paddles

	//bool BoxDepenatration(Ball);
	void Draw();
	
};

