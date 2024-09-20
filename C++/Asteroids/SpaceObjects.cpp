#include "SpaceObjects.h"

SpaceObject::SpaceObject()
{
	locationInfo =
	{
		{50, 50}, 
		{5,5},

	};
}

void SpaceObject::Update(float delta)
{
	locationInfo.pos.x += locationInfo.deltaVelocity.x;
	locationInfo.pos.y += locationInfo.deltaVelocity.y;



}

void SpaceObject::Draw(void)
{
	DrawCircle(locationInfo.pos.x, locationInfo.pos.y, 30, WHITE);

}
