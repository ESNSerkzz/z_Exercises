#pragma once
#include "GameSpaceData.h"
#include "algorithm"
#include "raymath.h"

struct hitResult
{
	bool collided;
	Vector2 normal;
	Vector2 position;
	float hitTime;
	float penetrationDepth;
};

struct AABB
{
	Vector2 pos;
	Vector2 size;
	AABB();
	AABB(Vector2 _pos, Vector2 _size);
	bool isOverlapped(AABB box, hitResult& hit);


	void Draw();

};

// CC means Circle Collision
struct CC
{
	Vector2 pos;
	float rad;
	CC();
	CC(Vector2 _pos, float _rad);
	bool isOverlapped(AABB box, hitResult& hit);

};

class Collisions
{
	CC circleBall;
	AABB boxPaddle;

	Collisions();
	//Circle (ball) V Rect (paddle/player)
	bool IsOverlapped()
	{

	}
};
