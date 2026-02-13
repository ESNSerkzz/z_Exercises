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
	AABB collision;
	int x;
	int y; 
	TileType tType = TileType(0);
	Tile();
	void DrawTile();
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
