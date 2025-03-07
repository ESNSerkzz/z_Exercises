#pragma once
#include "raylib.h"

class Ball
{
	Vector2 pos;
	float radius;

	Ball();

	void Update();
	void Draw();
};

