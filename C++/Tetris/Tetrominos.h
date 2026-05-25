#pragma once
#include "collisions.h"
#include "ScreenGrid.h"
#include "raylib.h"
#include <vector>


class Tetrominos
{
	ScreenGrid* screenMap;
public:
	std::vector<Tile>tetroTiles;
	float descentRateTimer;
	
	int x;
	int y;
	bool paused;

	int* lvl;

	ShapeType shape;

	Tetrominos();
	Tetrominos(ShapeType _bType, int* _lvl);
	
	//TODO 
	// --------------------------
	// add a seperate list of tetroTiles to the top right corner to represent the "next tile" 
	// the score (for soft drop)
	// the lose condition when overlapped.


	std::vector<Tile> BlockCanvas(std::vector<Tetrominos> tetromino);

	void CreateTetro(ShapeType _type);
	void Decention();
	void ResetTetro();
	void RotateTetro(double _rotation);
	
	void Input();
	void Update(float delta, ScreenGrid* map);
	void Draw();
};
