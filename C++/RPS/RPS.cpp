#include "RPS.h"

RPS::RPS()
{
	score = 0;
	choice = EMPTY;

}

RPS::RPS(std::string _inputChoice)
{
	score = 0;
	choice = EMPTY;
	
	
	
}

void RPS::takeInput()
{
	while (EMPTY == choice)
	{
		std::string inputChoice;
		std::cin >> inputChoice;
		char inputLetter = inputChoice[0];

	
			

			switch (inputLetter)
			{
			case 'R':
				choice = ROCK;
				break;
			case 'r':
				choice = ROCK;
				break;
			case 'P':
				choice = PAPER;
				break;
			case 'p':
				choice = PAPER;
				break;
			case 'S':
				choice = SCISSORS;
				break;
			case 's':
				choice = SCISSORS;
				break;
			default:
				std::cout << "Wrong input" << std::endl;
				break;
			}
	
	}
	std::cout << "good choice" << std::endl;
	return;
}

void RPS::Update()
{
	
	/*if( inputChoice == "R" || "r")
	{
		choice = ROCK;
		std::cout << "Rock" << std::endl;
	}
	else
	{
		std::cout << "nope" << std::endl;
	}*/
	
	
	
}
