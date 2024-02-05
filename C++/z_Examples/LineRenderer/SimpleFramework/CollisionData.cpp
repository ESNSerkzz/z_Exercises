
#include "CollisionData.h"

void CollisionData::PerformDepenetrationStep()
{
	if (depth < 0) return;

	thing1->position += normal * depth * 0.5f;
	thing2->position -= normal * depth * 0.5f;
}