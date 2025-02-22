#include "FieldAbilities.h"
#include <iostream>

FieldAbilities::FieldAbilities()
{
	/*abilityBox.pos = { screenWidth / 2 , screenHeight / 2 + 50 };
	abilityBox.pos = currentRandomPos;
	abilityBox.size = { 50, 50 };*/
	newPos(1);
	
	abilityBox.size = { 50, 50 };

	std::cout << abilityBox.pos.x << "\n";
	std::cout << abilityBox.pos.y << "\n";
	//std::sleep(10);


}

FieldAbilities::FieldAbilities(int seed)
{
	newPos(seed);

	abilityBox.size = { 50, 50 };

	std::cout << abilityBox.pos.x << "\n";
	std::cout << abilityBox.pos.y << "\n";
}

void FieldAbilities::newPos(int seed)
{
	srand(time(NULL) * (100 + seed));

	abilityBox.pos = { static_cast<float>((rand() % (screenWidth - 200)) + 100) , static_cast<float>((rand() % (screenHeight - borderHeight - borderHeight - 100)) + borderHeight + 50) };
}

void FieldAbilities::PowerUpAbility(int RandomSeedID)
{
	RandomSeedID = rand() % 3;
	int seedID = RandomSeedID;
	switch (seedID) {
	case 1:
		if (seedID == 1)
		{
			
		}
	}
}


//FieldAbilities::~FieldAbilities()
//{
//}

void FieldAbilities::Update()
{
	abilityBox.pos;
}

void FieldAbilities::Draw()
{
	abilityBox.Draw();
	
}
