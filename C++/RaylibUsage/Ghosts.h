#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Collisions.h"
#include "Constants.h"
#include "MapGrid.h"
#include "fstream"
#include <iostream>
enum GhostType
{
	//BLINKY , PINKY     , INKY      , CLYDE
	RED_GHOST, PINK_GHOST, CYAN_GHOST, ORAGANE_GHOST
};
class Ghosts
{
public:

	AABB box;
	Direction dir;
	float velocity;
	GhostType gType;
	MapGrid* ghostToMap;
	Texture2D ghostSprite;
	int currentFrame;
	int frameTimeLength;

	Ghosts();
	Ghosts(AABB _box, GhostType _gType, MapGrid* _ghostToMap , std::string filePath);

	void PathingMovement();
	void Update();
	void Draw();


};

