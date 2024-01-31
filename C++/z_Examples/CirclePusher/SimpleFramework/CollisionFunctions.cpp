#include "CollisionFunctions.h"

CollisionData GetCollision(Thing& thing1, Thing& thing2)
{
	Vec2 displacement = thing2.position - thing1.position;
	float centreDistances = glm::length(displacement);

	float overlapAmount = -centreDistances + thing1.radius + thing2.radius;
	
	CollisionData data;
	data.depth = overlapAmount;
	data.normal = displacement / centreDistances;
	data.thing1 = &thing1;
	data.thing2 = &thing2;
	return data;
}
