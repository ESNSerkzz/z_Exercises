#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Constants.h"
#include "Collisions.h"
#include "GameSpaceData.h"

class Ball : public GameDataInfo
{
public:
	CC ballCollision;

	Ball();
	Ball(Vector2 startVel);

	void Update(float delta);
	void Draw();
};
