#pragma once
#include "SpaceObjects.h"
#include "Constants.h"
#include "Bullets.h"

class Player :public SpaceObject 
{
public:
	SpaceObject playerObject;
	Player();
	void Draw();
	void Update(float delta);
	void Input(float delta);
	std::vector <Bullets> bullets;


	Trail pathForPlayer;
	//int PFP_offset = pathForPlayer - 20;
	
	//add a trail for the player (pretty much the exact same as the bullet ~max)
};