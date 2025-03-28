#pragma once
#include "collisions.h"
#include "Constants.h"
#include "GameSpaceData.h"
#include "raylib.h"

class BrickTiles : public GameDataInfo
{
public:
	AABB Bricks;
	BrickTiles();
	BrickTiles(Vector2 _pos, Vector2 _size);
	void Draw();
};

