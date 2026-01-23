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
	int rows; // Y
	int collumns; // X
	std::vector<Tile>
};
