#pragma once
#include "Constants.h"
#include "Collisions.h"
#include "fstream"
#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>

enum ShapeType
{
	I_shape, O_shape, T_shape, S_shape, Z_shape, L_shape, J_shape
};

enum TileType
{
	EMPTY, BRICK, TETROMINO
};

struct Tile
{
	int x; // in grid coords X.
	int y; // in grid coords Y.
	TileType tType = TileType(0);
	Color colourFill;
	Color colourLines;

	Tile();
	Tile(Vector2 _pos);
	Tile(TileType _type, int _x, int _y);

	void DrawTile(Color _lines, Color _fill);
	void Draw();
};

class ScreenGrid
{


public:
	bool gameOver;
	int* lvl;
	int score;
	int rowsCleared;
	ScreenGrid();
	ScreenGrid(int _columns, int _rows, int _tileSize, std::string _mapFilePath, int* _lvl);

	std::vector<std::vector <Tile>> listOfTiles_Grid;
	void HandleTetroLanding(std::vector<Tile> tetro);
	std::vector<int> FilledRowCheck();
	bool GameOver();
	void ScoreCalc(int _rowsClear);
	void Draw();
};
