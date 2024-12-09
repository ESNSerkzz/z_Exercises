#pragma once
#include "Paddles.h"
#include <iostream>

class Player : public Paddles
{
public:
	Player(int player_ID);

	int playerID;
	void Update(float delta);
	void Input(float delta);
};

