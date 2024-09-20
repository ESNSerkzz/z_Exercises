#include <iostream>
#include <string>
#pragma once


static int Arrays2D()
{
	
	int arrayGridSize[3][3]
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	for (int i = 0; i <= 2; i++)
	{
		

		for (int j = 0 ; j <= 2 ; j++) 
		{
			std::cout << arrayGridSize[i][j] << " ";
		}
		std::cout << "\n";
	}

	//std::cout << *arrayGridSize << std::endl;

	return 0;
}

int main()
{
	Arrays2D();
}