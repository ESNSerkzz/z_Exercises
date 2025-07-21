#pragma once
#include <vector>
#include "Palletes.h"
#include "fstream"
#include <iostream>
#include <string>
#include "raylib.h"
enum TileType
{
	EMPTY, BRICK, PALLETE, POWERPALLETE, FRUIT
};

struct Tile
{
	AABB TileCollision;
	int x;
	int y;
	int size;
	Palletes* pallet;
	TileType type = (TileType) 0;
};

class MapGrid
{
public:

	MapGrid();
	MapGrid(int columns, int rows, int tileSize);
	MapGrid(int columns, int rows, int tileSize, std::string filePath);
	std::vector<std::vector <Tile>> listOfTiles;
	
	void DrawBox(int x, int y);
	void Draw();

};