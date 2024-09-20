#include <iostream>
#include <string>
#include "raylib.h"

//using namespace std;
#pragma once


void PassByReference(int&);
void doingArrays();

int main()
{
	const int screensizeX = 800;
	const int screensizeY = 500;
	InitWindow(screensizeX, screensizeY, "window");
	
}
void PassByReference(int &myValue)
{
	myValue *= 2; // Does not modify the variable passed in!
	//std::cout << myValue << std::endl;
}

void doingArrays()
{
	int numbersArray[10] = { 1,2,3,4,5,6,7,8,9,10, };
	//std::cout << numbersArray[9] << std::endl;


	std::string userInput;
	std::cin >> userInput;
	
	int stringToInt = std::stoi(userInput);
	int* newNumberArray = new int[stringToInt];
	std::cout << sizeof(newNumberArray) << std::endl;

	for (int i = 0; i < stringToInt; i++)
	{
		std::cin >> newNumberArray[i];
	}

	for (int i = 0; i < stringToInt; i++)
	{
		std::cout << newNumberArray[i];
	}



	delete[] newNumberArray;
}