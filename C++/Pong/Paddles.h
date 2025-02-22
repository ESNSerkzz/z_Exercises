#pragma once
#include <raylib.h>
#include <raymath.h>
#include "Constants.h"
#include "ScreenObjects.h"
#include "AABB.h"
#include "Ball.h"

#define M_PI 3.14159

class Paddles : public ScreenObjects
{
public:
	Paddles();
	Paddles(Vector2 position, Vector2 size, float speed);
	
	Color colourSelection;

	void Update();
	void Draw();
	void HitBall(Ball& ball);
	

	AABB paddleCollision;

	//make Player1 and player2 - read sructs & classes and OOP

};

