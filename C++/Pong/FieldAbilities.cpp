#include "FieldAbilities.h"
#include <iostream>

FieldAbilities::FieldAbilities()
{
	
	newPos(1);
	
	abilityBox.size = { 80, 80 };

	
	std::cout << "AB pos x" << abilityBox.pos.x << "\n";
	std::cout << "AB pos y" << abilityBox.pos.y << "\n";
	
	deletable = false;

}

FieldAbilities::FieldAbilities(int seed, AbilityType typeNumber)
{
	newPos(seed);


	abilityBox.size = { 60, 60 };
	
	type = typeNumber;
	deletable = false;
	
}

FieldAbilities::FieldAbilities(int seed)
{
	newPos(seed);
	abilityBox.size = {60, 60};
	srand(time(NULL) * (100 * seed));
	type = AbilityType ((rand()% 2) + 1) ;
	std::cout << type << "\n";
	deletable = false;
}

void FieldAbilities::newPos(int seed)
{
	srand(time(NULL) * (100 * seed));
	deletable = false;
	abilityBox.pos = { static_cast<float>((rand() % (screenWidth - 200)) + 100) , static_cast<float>((rand() % (screenHeight - borderHeight - borderHeight - 100)) + borderHeight + 50) };
}

bool FieldAbilities::PowerUpAbility(Ball* ballA)
{
	


	switch (type) 
	{
	case SPEEDBOOST:
		
		
		ballA->dataInfo.speed = Vector2Multiply(ballA->dataInfo.speed, { 2.125, 2.125 });
		break;
	case BOUNCE:
		
		ballA->dataInfo.speed = Vector2Rotate(ballA->dataInfo.speed, PI);
		break;
	}
	return false;
}


FieldAbilities::~FieldAbilities()
{
}

void FieldAbilities::Update(float delta)
{

}

void FieldAbilities::Draw()
{
	
	
	switch (type)
	{
	case SPEEDBOOST:

		abilityBox.Draw(GREEN);
		
		
		break;
	case BOUNCE:

		abilityBox.Draw(YELLOW);
		break;
	}
}
