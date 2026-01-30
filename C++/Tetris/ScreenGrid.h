#pragma once
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
	TileType tType;
	Tile();
	void DrawTile();
};

struct TileCoords : public Tile
{
	TileCoords();
	TileCoords(int _x, int _y);

};

class ScreenGrid
{
	ScreenGrid();
	ScreenGrid(int _columns, int _rows, int _tileSize, std::string _mapFilePath);

	std::vector<std::vector <Tile>> listOfTiles_Grid;
};
