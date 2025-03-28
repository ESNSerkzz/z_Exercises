#pragma once
#include "collisions.h"
#include "Constants.h"
#include "GameSpaceData.h"
#include "raylib.h"


class Paddle : public GameDataInfo
{
public:
	AABB boxCollision;

	Paddle();

	void Input(float delta);
	void Update();
	void Draw();
};

