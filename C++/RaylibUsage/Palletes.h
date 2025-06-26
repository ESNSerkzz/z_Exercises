#pragma once
#include "Raylib.h"
#include "Collisions.h"
#include "Constants.h"
#include <vector>

class Palletes
{
public:
	AABB box;
	Palletes();
	Palletes(Vector2 _pos, float _size);
	void Update();
	void Draw();
};
