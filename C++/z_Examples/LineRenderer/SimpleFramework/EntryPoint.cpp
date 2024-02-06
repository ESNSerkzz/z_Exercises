#include <iostream>
#include "ApplicationHarness.h"

//Include the necessary header file here for your game type
#include "Engine.h"


#include <vector>


int main()
{
	std::vector<char> stuff = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	

	for (int i = 0; i < stuff.size(); i++)
	{
		for (int j = i+1; j < stuff.size(); j++)
		{
			std::cout << stuff[i] << " ";
			std::cout << stuff[j] << std::endl;
		}
	}



	ApplicationHarness program(new Engine());	//Create a new instance of your application type to pass into the harness here.

	program.Run();

	return 0;
}