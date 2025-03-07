#pragma once
#include "AABB.h"
#include "Ball.h"
#include "Constants.h"
#include "ScreenObjects.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class FieldAbilities
{
public:
	AABB abilityBox;


	//currentRandomPos = {randomPosX, randomPosY};
	//making powerUP boxes and sprinkling them randomly throughout the field using the "random" info that max sent me.
	// HINT: construct it like this - {} {} (for position)
	
	FieldAbilities();
	FieldAbilities(int seed);
	void newPos(int seed);
	bool PowerUpAbility(int RandomAbilityID);

	void Update(float delta);
	void Draw();
	
	~FieldAbilities();
	
};

