#pragma once
#include "Constants.h"
#include "SpaceObjects.h"
#include "Trail.h"

class Bullets : public SpaceObject 
{
public:

	Bullets(GameSpacePosition* pos, float speed);
	void Draw() override;
	void Update(float delta);

	bool bulletDeletable;
	int bulletAge;

	Trail path;
	
};
