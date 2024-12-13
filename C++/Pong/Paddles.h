#pragma once
#include <raylib.h>
#include "Constants.h"
#include "ScreenObjects.h"
#include "AABB.h"

class Paddles : public ScreenObjects
{
public:
	Paddles();
	Paddles(Vector2 position, Vector2 size, float speed);
	
	Color colourSelection;

	void Update();
	void Draw();
	
	AABB paddleCollision;

	//make Player1 and player2 - read sructs & classes and OOP

};

