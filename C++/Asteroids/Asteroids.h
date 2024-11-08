#pragma once
#include "SpaceObjects.h"
#include <random>

class Asteroid : public SpaceObject 
{
public:
	Asteroid();

	Asteroid(Vector2 startPos, Vector2 velocity, int size);
	
	void Draw() override;

	void Update(float delta) override;
};