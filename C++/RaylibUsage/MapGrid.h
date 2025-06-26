#pragma once
#include <vector>
#include "Palletes.h"

#include "raylib.h"

struct Tile
{
	int x;
	int y;
	int size;
	Palletes* pallet;
};

class MapGrid
{
public:
	MapGrid();
	MapGrid(int columns, int rows, int tileSize);
	std::vector<std::vector <Tile>> listOfTiles;
	void Draw();

};