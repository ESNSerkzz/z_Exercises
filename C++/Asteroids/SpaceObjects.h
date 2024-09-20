#pragma once
#include "Constants.h"
#include "raylib.h"

struct GameSpacePosition
{
	Vector2 pos;
	Vector2 deltaVelocity;
};

typedef class SpaceObject
{
public:

	SpaceObject();


	GameSpacePosition locationInfo;
	void Update(float delta);
	void Draw(void);

};


