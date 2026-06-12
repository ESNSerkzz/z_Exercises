#pragma once
#include "collisions.h"
#include "ScreenGrid.h"
#include "raylib.h"
#include <vector>


class Tetrominos
{
	ScreenGrid* screenMap;
public:

	Tetrominos* nextTetro;

	std::vector<Tile>tetroTiles;
	float descentRateTimer;
	
	int x;
	int y;
	bool paused;

	int* lvl;

	ShapeType shape;

	Tetrominos();
	Tetrominos(ShapeType _bType, int* _lvl, bool inCanvas);
	
	//TODO 
	// --------------------------
	// the lose condition when overlapped. and the GameOver UI/button that goes with it.
	
	void CreateTetro(ShapeType _type, bool inCanvas);
	void Decention();
	void ResetTetro();
	void RotateTetro(double _rotation);
	void SetToCanvas();
	void SetToGame();

	void Input();
	void Update(float delta, ScreenGrid* map);
	void Draw();
};
