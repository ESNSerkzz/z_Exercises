#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Collisions.h"
#include "Constants.h"
#include "MapGrid.h"

class Pacman
{
public:
	CC circle;
	Direction dir;
	float velocity;
	int score;

	MapGrid* pacToMap;
		
	Pacman(MapGrid*_pacToMap);

	void Input();
	void Update();
	
	//void scoreAdder(int score);

	void Draw();

};