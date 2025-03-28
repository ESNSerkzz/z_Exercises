#pragma once
#include "raylib.h"

struct DataInfo
{
	Vector2 pos;
	Vector2 size;
	Vector2 vel;
	float radius;
};

class GameDataInfo
{
public:
	DataInfo dataInfo;

	void Draw();
	void Update(float delta);
};