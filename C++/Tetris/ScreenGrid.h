#pragma once
#include "Constants.h"
#include "Collisions.h"
#include "Tetrominos.h"
#include "fstream"
#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>



class ScreenGrid
{


public:
	ScreenGrid();
	ScreenGrid(int _columns, int _rows, int _tileSize, std::string _mapFilePath);

	std::vector<std::vector <Tile>> listOfTiles_Grid;
	
	void Draw();
};
