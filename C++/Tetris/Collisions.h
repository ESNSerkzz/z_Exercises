#pragma once
#include "Constants.h"
#include "raylib.h"
#include "raymath.h"
struct HitResult
{
	bool collisionDetection;
	Vector2 pos;
	Vector2 normal;
	float pDepth;
};

class AABB
{
public:
	Vector2 pos;
	Vector2 size;
	AABB();
	AABB(Vector2 _pos);
	bool IsOverlapped(AABB box);
	void DrawAABB(Color _FillColour);

};

