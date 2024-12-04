#pragma once
#include "ScreenObjects.h"
#include "Constants.h"
class Ball : public ScreenObjects
{
public:
	Ball();
	Ball(Vector2 startVel);

	void Draw(void) override;
	void Update() override;

};

