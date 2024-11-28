#pragma once
#include <raylib.h>
#include "Constants.h"
#include "ScreenObjects.h"

class Paddles : public ScreenObjects
{
public:
	Paddles();
	Paddles(Vector2 position, Vector2 size, float speed);
	

	void Update();
	void Draw();

	//make Player1 and player2 - read sructs & classes and OOP

};

