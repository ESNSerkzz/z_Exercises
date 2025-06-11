#pragma once
#include "AABB.h"
#include "Ball.h"
#include "Constants.h"
#include "ScreenObjects.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

enum AbilityType {

	SPEEDBOOST = 1,
	BOUNCE = 2
};

class FieldAbilities
{
public:
	AABB abilityBox;
	AbilityType type;
	bool deletable;
	
	
	FieldAbilities();
	FieldAbilities(int seed, AbilityType typeNumber);
	FieldAbilities(int seed);
	void newPos(int seed);
	bool PowerUpAbility(Ball* ballA);

	void Update(float delta);
	void Draw();
	
	~FieldAbilities();
	
};

