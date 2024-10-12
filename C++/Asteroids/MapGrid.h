#pragma once
#include <Vector>
#include "Constants.h"
#include "raylib.h"
#include <utility>

enum imageType
{
	SHIP,
	ASTEROID,
	BULLET
};

class MapGrid
{
public:
	Vector2 startPos = { 0.0 };
	Vector2 endPos = { screenHeight, screenWidth };
	

	void Draw(float rotation, Vector2 scale, Vector2 pos);
	MapGrid();
	MapGrid(imageType type);


	std::vector<std::pair<float, float>> points;


};

