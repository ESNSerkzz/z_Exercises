#pragma once
#include "Maths.h"
#include "Thing.h"

struct CollisionData
{
	Vec2 normal;	//Points from 1 to 2
	float depth;


	Thing* thing1 = nullptr;
	Thing* thing2 = nullptr;


	void PerformDepenetrationStep();
};
