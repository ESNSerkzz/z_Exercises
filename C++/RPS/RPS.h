#pragma once
#include "raylib.h"
#include <string>
#include <iostream>

enum RPS_Type
{
	ROCK, PAPER, SCISSORS, EMPTY
};

class RPS
{
public:
	
	
	RPS_Type choice;
	int score;
	RPS();
	RPS(std::string _inputChoice);
	void takeInput();


	void Update();
};

