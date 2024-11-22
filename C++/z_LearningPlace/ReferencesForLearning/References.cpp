#include <string>
#include <iostream>

void DeclaringReference();
void HowNotToDeclareReference();
void highScore();
int main() 
{
	//HowNotToDeclareReference();
	highScore();
}

void DeclaringReference()
{
	int playerScore = 10;
	int &highScore = playerScore; // create a reference to an int.
}

void HowNotToDeclareReference()
{
	int playerScore = 10;
	int /*&*/highScore;
	// You cannot declare a reference and later assign it with a value
	highScore = playerScore; // does not work.
	std::cout << "HowNotToDelcareReference:" << std::endl;
	std::cout << highScore << std::endl;


	/*
	int playerScore = 10;
	int& highScore = &playerScore; // does not work. must be an object.
	*/
	
}

void highScore()
{
	int playerScore;
	int* highScore = &playerScore;

	std::cout << "playerScore";
	std::cin >> playerScore;
	std::cout << playerScore << std::endl;

	std::cout << "*highscore: " << std::endl;
	std::cout << *highScore << "\n";
	std::cout << &highScore;
}
