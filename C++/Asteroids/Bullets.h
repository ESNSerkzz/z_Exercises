#pragma once
#include "Constants.h"
#include "SpaceObjects.h"

class Bullets : public SpaceObject 
{
public:

	Bullets(GameSpacePosition* pos, float speed);
	void Draw() override;
	bool deletable;

	//make it actually delete using its "alive time" and and its deletability
};
