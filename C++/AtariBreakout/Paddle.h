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

	int playerScore;

	void AddScorePoints(int points);
	void Input(float delta);
	void Update();
	void Draw();
};

