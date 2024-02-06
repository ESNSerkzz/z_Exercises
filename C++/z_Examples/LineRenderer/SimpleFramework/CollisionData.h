#pragma once
#include "Maths.h"
#include "Thing.h"

class CollisionData
{
public:
	Vec2 normal; //The normal should always point from Thing1 towards Thing2
	//Therefore, depenetration will involve moving Thing2 in the normal direction, and Thing1 in the opposite to the normal direction
	float depth;

	Thing* thing1 = nullptr;
	Thing* thing2 = nullptr;

	void PerformDepenetrationStep();
};
