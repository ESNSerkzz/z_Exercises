#pragma once
#include <raylib.h>
//#include "Paddles.h"
#include "Constants.h"

struct GameSpaceInfo
{
	Vector2 pos;
	Vector2 scaleSize;
	float speed;
};


typedef class ScreenObjects
{
public:
	ScreenObjects();

	GameSpaceInfo dataInfo;

	void Draw(void);
	void Update();

};

