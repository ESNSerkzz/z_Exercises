#pragma once
#include "AABB.h"
#include "ScreenObjects.h"
#include "Constants.h"

class Ball : public ScreenObjects
{
public:
	
	Ball(Vector2 startVel);

	void Draw(void) override;
	void Update(float delta) override;
	void verticalBounce(float delta);
	AABB ballCollision;
	
};

