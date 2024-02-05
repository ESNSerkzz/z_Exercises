#pragma once
#include "Maths.h"
#include "Thing.h"

class CollisionData
{
public:
	Vec2 normal;
	float depth;

	Thing* thing1 = nullptr;
	Thing* thing2 = nullptr;

	void PerformDepenetrationStep();
};
