#pragma once
#include "SpaceObjects.h"
#include "Constants.h"
#include "Bullets.h"

class Player :public SpaceObject 
{
public:
	SpaceObject playerObject;
	Player();
	int playerScore;
	void addPoints(int points);
	int getScore();

	void Draw();
	void Update(float delta);
	void Input(float delta);
	std::vector <Bullets> bullets;


	Trail pathForPlayer;
	//int PFP_offset = pathForPlayer - 20;
	

};