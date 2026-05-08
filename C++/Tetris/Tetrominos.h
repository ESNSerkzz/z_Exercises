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

	ShapeType shape;

	Tetrominos();
	Tetrominos(ShapeType _bType);
	
	
	std::vector<Tile> BlockCanvas(Tetrominos tetromino);
	void Decention();
	void ResetTetro();
	void CreateTetro(ShapeType _type);
	void RotateTetro(double _rotation);
	void Input();
	void Update(float delta, ScreenGrid* map);
	void Draw();
};
