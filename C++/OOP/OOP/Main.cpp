#include <iostream>
#include <cstdlib>
#include <string>

int rps(std::string choice);


int main() 
{
	std::string selectChoice; 
	std::cout << "Play Rock, paper, scissors \n";
	std::cout << "Rock? Paper? Scissor?: ";
	std::cin >> selectChoice;
	
	
	rps("rock");
	rps("paper");
	rps("scissors");
	
	

	//if (rps(0) != selectChoice)
	
	return 1;

}

int rps(std::string choice)
{
	int userChoice;
	int opponentChoice;

	if (choice == "rock")
	{
		userChoice = 0;
	}
	if (choice == "paper")
	{
		userChoice = 1;
	}
	if (choice == "scissors")
	{
		userChoice = 2;
	}

	if (choice != userChoice)
	{
		std::cout << "Please select by proper name (lowercase)";
	}

	opponentChoice = std::rand() % 4;

	opponentChoice--;
	
	switch (userChoice)
	{
	case 0:
		if (opponentChoice == 0)
		{
			return 0;

		}
		if (opponentChoice == 1)
		{
			return 2;

		}
		if (opponentChoice == 2)
		{
			return 1;

		}
		break;

	case 1:
		if (opponentChoice == 0)
		{
			return 0;

		}
		if (opponentChoice == 1)
		{
			return 2;

		}
		if (opponentChoice == 2)
		{
			return 1;

		}
		break;

	case 2:
		if (opponentChoice == 0)
		{
			return 0;

		}
		if (opponentChoice == 1)
		{
			return 2;

		}
		if (opponentChoice == 2)
		{
			return 1;

		}

	}


	// set 0,1,2 for tie win and lose

};
//int TieWinlose()
//{
//
//}
