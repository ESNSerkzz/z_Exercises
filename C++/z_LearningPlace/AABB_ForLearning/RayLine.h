#pragma once
#include "raylib.h"
#include "raymath.h"
struct RayLine
{
	// StartPoint EndPoint
	Vector2 ray_SP;
	Vector2 ray_dir;
	
	
	RayLine();
	RayLine(Vector2 start, Vector2 end);
	
	void Draw(Color c);

};


