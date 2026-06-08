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
	// add a seperate list of tetroTiles to the top right corner to represent the "next tetromino piece" 
	// the score (for soft drop)
	// the lose condition when overlapped.


	//void BlockCanvas(std::vector<Tile> nextTetrosTiles);
	//void BlockCanvas(Tetrominos nextTetro);
	
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
