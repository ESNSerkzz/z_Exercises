#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Collisions.h"
#include "Constants.h"

class Pacman
{
public:
	AABB box;
	
	Direction dir;
	float velocity;
	int score;

	
	Pacman();

	void Update();
	
	//void scoreAdder(int score);

	void Draw();

};