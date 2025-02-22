#pragma once
#include "AABB.h"
#include "ScreenObjects.h"
#include "Constants.h"
#include "raymath.h"

class Ball : public ScreenObjects
{
public:
	Ball();
	Ball(Vector2 startVel);

	void Draw(void) override;
	void Update(float delta) override;
	void Bounce(float delta);
	AABB ballCollision;
	
};

