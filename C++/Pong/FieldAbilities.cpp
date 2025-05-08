#include "FieldAbilities.h"
#include <iostream>

FieldAbilities::FieldAbilities()
{
	/*abilityBox.pos = { screenWidth / 2 , screenHeight / 2 + 50 };
	abilityBox.pos = currentRandomPos;
	abilityBox.size = { 50, 50 };*/
	newPos(1);
	
	abilityBox.size = { 80, 80 };

	std::cout << "AB pos x" << abilityBox.pos.x << "\n";
	std::cout << "AB pos y" << abilityBox.pos.y << "\n";
	//std::sleep(10);


}

FieldAbilities::FieldAbilities(int seed, AbilityType newType)
{
	newPos(seed);


	abilityBox.size = { 50, 50 };
	type = newType;
	
}

void FieldAbilities::newPos(int seed)
{
	srand(time(NULL) * (100 + seed));

	abilityBox.pos = { static_cast<float>((rand() % (screenWidth - 200)) + 100) , static_cast<float>((rand() % (screenHeight - borderHeight - borderHeight - 100)) + borderHeight + 50) };
}

bool FieldAbilities::PowerUpAbility(Ball* ballA)
{
	


	switch (type) 
	{
	case SPEEDBOOST:
		
		
		ballA->dataInfo.speed = Vector2Multiply(ballA->dataInfo.speed, { 1.125, 1.125 });
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
	//abilityBox.pos;
}

void FieldAbilities::Draw()
{
	abilityBox.Draw();
	
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
