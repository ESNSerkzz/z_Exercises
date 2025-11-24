#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Collisions.h"
#include "Constants.h"
#include "MapGrid.h"
#include "Pacman.h"
#include "fstream"
#include <iostream>
#include <vector>
enum GhostType
{
	//BLINKY , PINKY     , INKY      , CLYDE
	RED_GHOST, PINK_GHOST, CYAN_GHOST, ORANGE_GHOST
};
enum Behaviour
{
	CHASE, SCATTER, FRIGHTENED, SPAWN
};

class Ghosts
{
public:

	CC collision;
	Direction dir;
	float velocity;
	GhostType gType;
	Behaviour currentBehaviour;
	MapGrid* ghostToMap;
	Texture2D ghostSprite;
	int currentFrame;
	int frameTimeLength;
	Pacman* pacman;


	Ghosts();
	Ghosts(CC _collision, GhostType _gType, MapGrid* _ghostToMap , std::string filePath);

//	std::vector<tileCoords> dijkstra(tileCoords _targetPos);
	void PathingMovement();
	void Update(float delta);
	void Draw();

private:
	void HandleColisions();
	std::vector<tileCoords> path;
};

