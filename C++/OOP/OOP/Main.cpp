#include <iostream>
#include <cstdlib>
#include <string>

int rps(std::string choice);


int main()
{
	std::string selectChoice;
	std::cout << "Play Rock, paper, scissors \n";
	std::cout << "Rock? Paper? Scissor?: ";
	

	int userScore = 0;
	int opponentScore = 0;

	while (userScore < 5 && opponentScore < 5)
	{
		int  status = 0;
		while (status == 0)
		{
			std::cin >> selectChoice;
			status = rps(selectChoice);
		}
		if (status == -1)
		{
			std::cout << "error 303 \n";
			status = 0;

		}
		if (status == 1)
		{
		
			std::cout << "draw, go again \n";
		}
		if (status == 2) 
		{
			std::cout << "you win a point \n";
			userScore++;
		}
		if (status == 3)
		{
			opponentScore++;
			std::cout << "womp womp \n";
		}
		std::cout << "User score: " << userScore <<  " \nOpponent Score:" << opponentScore << "\n";
	}
	if (userScore > opponentScore)
	{
		std::cout << "you win.\n";
	}

	else
	{
		std::cout << "you suk\n";
	}

	return 1;

}

int rps(std::string choice)
{
	int userChoice;
	int opponentChoice;

	if (choice == "rock")
	{
		userChoice = 1;
	}
	else if (choice == "paper")
	{
		userChoice = 2;
	}
	else if (choice == "scissors")
	{
		userChoice = 3;
	}

	else
	{
		std::cout << "Please select by proper name (lowercase)";
		return 0;
	}

	opponentChoice = std::rand() % 3;

	//opponentChoice--;

	switch (userChoice)
	{
	case 1:
		if (opponentChoice == 0)
		{	
			return 1;
		}
		if (opponentChoice == 1)
		{
			return 3;
		}
		if (opponentChoice == 2)
		{
			return 2;
		}
		break;
	case 2:
		if (opponentChoice == 0)
		{
			return 2;
		}
		if (opponentChoice == 1)
		{
			return 1;
		}
		if (opponentChoice == 2)
		{
			return 3;
		}
		break;

	case 3:
		if (opponentChoice == 0)
		{
			return 3;

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

	return -1;
	// set 1,2,3 for tie win and lose

};
//int TieWinlose()
//{
//
//}
