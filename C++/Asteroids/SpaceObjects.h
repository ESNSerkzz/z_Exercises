#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Constants.h"
#include "MapGrid.h"


struct GameSpacePosition
{
	Vector2 pos;
	Vector2 deltaVelocity;
	float rotation;
	int size;
};

typedef class SpaceObject
{
public:

	SpaceObject();


	GameSpacePosition locationInfo;

	MapGrid tiles;
	bool toDelete;

	virtual void Update(float delta);
	virtual void Draw(void);

	void WrapCoordinates(float ix, float iy, float& ox, float& oy);
	
	virtual void AddRotation(float rotate, float delta);
	virtual void AddThrust(float thrust, float delta);

	bool isOverlapped(Vector2 point);

};



