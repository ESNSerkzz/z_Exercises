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
	int currentFrame;
	int mouthOpenFrames;
	Texture2D pacmanSprite;
	MapGrid* pacToMap;
		
	Pacman();
	Pacman(MapGrid*_pacToMap);

	void Input();
	void Update(float delta);
	
	void scoreAdder(int _score);

	void Draw();

};