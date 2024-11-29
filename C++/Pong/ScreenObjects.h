#pragma once
#include <raylib.h>
//#include "Paddles.h"
#include "Constants.h"

struct GameSpaceInfo
{
	Vector2 pos;
	Vector2 scaleSize;
	Vector2 speed;
};


typedef class ScreenObjects
{
public:
	ScreenObjects();

	GameSpaceInfo dataInfo;

	virtual void Draw(void);
	virtual void Update();

};

