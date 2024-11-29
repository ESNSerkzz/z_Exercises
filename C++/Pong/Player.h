#pragma once
#include "Paddles.h"

class Player : public Paddles
{
public:
	Player(int player_ID);

	int playerID;

	void Input();
};

