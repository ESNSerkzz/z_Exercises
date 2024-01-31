#pragma once

#include "Maths.h"
#include "LineRenderer.h"

class Thing
{
public:
	Vec2 position;

	float radius = 1.0f;

	Thing() {}
	Thing(float xPos, float yPos);

	void Update(float delta);

	void Draw(LineRenderer* lines);

};