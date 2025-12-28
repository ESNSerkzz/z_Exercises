#pragma once
#include "Constants.h"
#include "raylib.h"
#include "raymath.h"
struct HitResult;

class AABB
{
public:
	Vector2 pos;
	Vector2 size;
	AABB();
	AABB(Vector2 _pos);
	bool IsOverlapped(AABB box);

};

