#pragma once
#include "raylib.h"
#include "raymath.h"
#include "AABB.h"




class Pacman
{
public:
	AABB box;
	
	Direction dir;
	float speed;
	int score;

	
	Pacman();

	void Update(bool canMove);
	
	void scoreAdder(int score);

	void Draw();

};