#pragma once
#include "raylib.h"
struct RayLine
{
	// StartPoint EndPoint
	Vector2 ray_SP;
	Vector2 ray_EP;
	float dir;
	
	RayLine();
	RayLine(Vector2 start, Vector2 end, float rayDir);
	
	void Draw(Color c);

};


