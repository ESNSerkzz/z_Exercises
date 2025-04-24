#include "FieldAbilities.h"
#include <iostream>

FieldAbilities::FieldAbilities()
{
	/*abilityBox.pos = { screenWidth / 2 , screenHeight / 2 + 50 };
	abilityBox.pos = currentRandomPos;
	abilityBox.size = { 50, 50 };*/
	newPos(1);
	
	abilityBox.size = { 80, 80 };
	PowerUpAbility(0);

	std::cout << "AB pos x" << abilityBox.pos.x << "\n";
	std::cout << "AB pos y" << abilityBox.pos.y << "\n";
	//std::sleep(10);


}

FieldAbilities::FieldAbilities(int seed)
{
	newPos(seed);

	abilityBox.size = { 50, 50 };

	
}

void FieldAbilities::newPos(int seed)
{
	srand(time(NULL) * (100 + seed));

	abilityBox.pos = { static_cast<float>((rand() % (screenWidth - 200)) + 100) , static_cast<float>((rand() % (screenHeight - borderHeight - borderHeight - 100)) + borderHeight + 50) };
}

bool FieldAbilities::PowerUpAbility(int RandomAbilityID)
{
	
	//RandomSeedID = rand() % 3;
	RandomAbilityID = 1;

	int AbilityID = RandomAbilityID;
	switch (AbilityID) 
	{
	case 1:
		AbilityID = 1;
		
		break;
	case 2:
		AbilityID = 2;
		
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
	
}
