#pragma once
#include "collisions.h"
#include "raylib.h"
#include <vector>
enum BlockType
{
	I_shape, O_shape, T_shape, S_shape, Z_shape, L_shape, J_shape
};

class Blocks
{
public:
	AABB box;
	BlockType shape;
	Blocks();
	Blocks(AABB _box, BlockType _bType);
	void Update();
	void Draw();
};

