#pragma once
#include "ScreenObjects.h"
class Ball : public ScreenObjects
{
	Ball(Vector2 startVel);

	void Draw(void) override;
	void Update() override;

};

