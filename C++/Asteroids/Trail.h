#pragma once
#include "raylib.h"
#include "vector"
#include "raymath.h"
#include "Constants.h"

class Trail
{
public:
	Trail();
	Trail(int max_Size, uint32_t Colour_A, uint32_t Colour_B);

	~Trail();

	void draw();
	void insert(Vector2 pos);

	std::vector<Vector2> points;
	int maxSize;
	uint32_t startColour;
	uint32_t endColour;



};