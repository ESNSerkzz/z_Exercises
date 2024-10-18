#include "SpaceObjects.h"
#include "raymath.h"

SpaceObject::SpaceObject()
{
	tiles = MapGrid(ASTEROID);
	locationInfo =
	{
		{50, 50},
		{10,10},
		0.0f,
	};
}

void SpaceObject::Update(float delta)
{
	


	locationInfo.pos.x += locationInfo.deltaVelocity.x;
	locationInfo.pos.y += locationInfo.deltaVelocity.y;


	WrapCoordinates(locationInfo.pos.x, locationInfo.pos.y, locationInfo.pos.x, locationInfo.pos.y);
}

void SpaceObject::Draw(void)
{
	//DrawCircle(locationInfo.pos.x, locationInfo.pos.y, 30, WHITE);
	tiles.Draw(locationInfo.rotation, { 20, 20 }, locationInfo.pos);
}

void SpaceObject::WrapCoordinates(float ix, float iy, float& ox, float& oy)
{
	ox = ix;
	oy = iy;
	if (ix < 0.0f) ox = ix + (float)screenWidth;
	if (screenWidth < ox) ox = ix - (float)screenWidth;
	if (iy < 0.0f) oy = iy + (float)screenHeight;
	if (screenHeight < oy) oy = iy - (float)screenHeight;

	return;

}

void SpaceObject::AddRotation(float rotate, float delta)
{
	locationInfo.rotation += rotate * delta;
}

void SpaceObject::AddThrust(float thrust, float delta)
{
	locationInfo.deltaVelocity.x += sin(locationInfo.rotation) * thrust * delta;
	locationInfo.deltaVelocity.y += -cos(locationInfo.rotation) * thrust * delta;

}
