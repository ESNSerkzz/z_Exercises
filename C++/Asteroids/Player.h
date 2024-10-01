#pragma once
#include "SpaceObjects.h"
#include "Constants.h"


class Player :public SpaceObject 
{
public:
	SpaceObject playerObject;
	Player();
	void Draw();
	void Update(float delta);
	void Input(float delta);

};