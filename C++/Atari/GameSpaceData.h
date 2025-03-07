#pragma once
#include "raylib.h"

struct DataInfo
{
	Vector2 pos;
	Vector2 size;
	float vel;
	float radius;
};

class GameDataInfo
{
public:
	DataInfo dataInfo;
};
