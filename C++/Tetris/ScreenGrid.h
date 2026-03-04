#pragma once
#include "Constants.h"
#include "Collisions.h"
#include "fstream"
#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>

enum TileType
{
	EMPTY, BRICK, BLOCK
};

struct Tile
{
	AABB collision; // in pixel coords.
	int x; // in grid coords X.
	int y; // in grid coords Y.
	TileType tType = TileType(0);
	Tile();
	Tile(Vector2 _pos);
	void DrawTile(Color _lines, Color _fill);
	void Draw();
};

struct TileCoords : public Tile
{
	TileCoords();
	TileCoords(int _x, int _y);

};

class ScreenGrid
{

public:
	ScreenGrid();
	ScreenGrid(int _columns, int _rows, int _tileSize, std::string _mapFilePath);

	std::vector<std::vector <Tile>> listOfTiles_Grid;

	void Draw();
};
