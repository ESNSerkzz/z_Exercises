#include <iostream>
using namespace std;
//Write a function called Swap that takes two integers.

static void Swap(int x, int y);


int main()
{

	//Declare two integers, x and y, and give them different values.
	int x = 3;
	int y = 6;
	Swap(x, y);

	//Print out the values here to the console, showing that they've been swapped.
	std::cout <<  x  << y << '\n';

}


void Swap(int x, int y)
{
	
	int temp = x;
	x = y;
	y = temp;
	
	
	//int x = y;
	//int y = x;
	//
	//x = 10;
	//y = 5;
	//
	//std::cout << x << std::endl;
}