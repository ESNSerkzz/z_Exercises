#pragma once
#include "Constants.h"
#include "GameSpaceData.h"
#include "raylib.h"


class Paddle : public GameDataInfo
{
public:
	Paddle();

	void Input();
	void Update();
	void Draw();
};

