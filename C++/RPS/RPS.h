#pragma once
#include "raylib.h"
#include <string>
#include <iostream>

enum RPS_Type
{
	ROCK, PAPER, SCISSORS
};

class RPS
{
public:

	std::string inputChoice;
	RPS_Type choice;
	int score;
	RPS();
	RPS(std::string _inputChoice);

	void Update();
};

