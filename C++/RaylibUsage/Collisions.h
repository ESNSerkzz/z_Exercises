#pragma once
#include "raylib.h"
#include "raymath.h"

enum Direction
{
	Up, Right, Down, Left
};

struct CollisionResults
{
	bool collisionDetection;
	Vector2 pos;
	Vector2 normal;

};
class CC
{
public:
	Vector2 pos;
	float size;

	CC(Vector2 _pos, float _size);
	void Update(Vector2 _pos);
	void Draw();

};

typedef class AABB
{
public:
	Vector2 pos;
	Vector2 halfSize;


	AABB() {}
	AABB(Vector2 centre, Vector2 _halfSize) : pos(centre), halfSize(_halfSize) {};
	void Draw();
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

