#pragma once
#include "Paddles.h"
#include "AABB.h"
#include <iostream>

class Player : public Paddles
{
public:
	Player(int player_ID);

	int playerID;
	int playerScore;
	void Update(float delta);
	void Input(float delta);
	void PaddleRally(int rallyS);
	void AddScore(int score);
	
	
	
};

