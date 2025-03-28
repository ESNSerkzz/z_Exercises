#pragma once
#include "Constants.h"
#include "Collisions.h"
#include "GameSpaceData.h"
#include "raylib.h"
#include "raymath.h"

class Ball : public GameDataInfo
{
public:
	CC ballCollision;

	Ball();
	Ball(Vector2 startVel);

	void Update(float delta);
	void Draw();
};

