#include "RPS.h"

RPS::RPS()
{
	score = 0;
	choice = ROCK;

}

RPS::RPS(std::string _inputChoice)
{
	score = 0;
	choice = ROCK;
	//std::cin >> _inputChoice;
	//inputChoice = _inputChoice;
	//switch(hoice)
	/*if (inputChoice == "R" || "r" || "P" || "p" || "S" || "s")
	{
		std::cout << "good choice" << std::endl;
	}
	else
	{
		std::cout << "Wrong input" << std::endl;

	}*/
	
}

void RPS::Update()
{
	
	if( inputChoice == "R" || "r")
	{
		choice = ROCK;
		std::cout << "Rock" << std::endl;
	}
	else
	{
		std::cout << "nope" << std::endl;
	}
	
	
	
}
