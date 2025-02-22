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
	//making powerUP boxes and spinlkling them randomly thoughout the field using the "random" info that max sent me.
	// HINT: constuct it like this - {} {} (for position)
	
	FieldAbilities();
	FieldAbilities(int seed);
	void newPos(int seed);
	void PowerUpAbility(int RandomSeedID);

	void Update();
	void Draw();
	
	//~FieldAbilities();
	
};

