#pragma once
#include "raylib.h"
#include "raymath.h"

enum Direction
{
	Up, Right, Down, Left
};


typedef class AABB
{
public:
	Vector2 pos;
	Vector2 halfSize;


	AABB() {}
	AABB(Vector2 centre, Vector2 _halfSize) : pos(centre), halfSize(_halfSize) {};

	//Overlapping func
	//messuring VEc2 point - does vect2 overlap?
	//AABB- if one box overlaps with another?

	bool overlaps(AABB box)
	{

		return(
			pos.x - halfSize.x < box.pos.x + box.halfSize.x &&
			pos.x + halfSize.x > box.pos.x - box.halfSize.x &&
			pos.y - halfSize.y < box.pos.y + box.halfSize.y &&
			pos.y + halfSize.y > box.pos.y - box.halfSize.y);

	}
	Direction GetDir(AABB box);

	bool overlaps(Vector2 point)
	{
		return (
			point.x > pos.x - halfSize.x &&
			point.x < pos.x + halfSize.x &&
			point.y > pos.y - halfSize.y &&
			point.y < pos.y + halfSize.y
			);
	}
};

