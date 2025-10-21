#include <iostream>
#include <string>

void FixedArrays();
void DynamicArrays();
void MultiDimArrays();


void main()
{
	FixedArrays();
	DynamicArrays();
	MultiDimArrays();
}

//Declaring Arrays - fixed sized
void FixedArrays()
{
	float distanceMeasurements[3];

	//Initailize List size
	float measurementsM_1[3] = { 1.2f, 2.5f, 3.7f };

	//Implied size
	float measurementsM_2[] = { 2.2f, 4.5f, 6.7f };

	
	std::cout << "Fixed sized arrays" << std::endl; //dialog
	std::cout << "Initialised List size" << std::endl; //dialog
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_1[i] << "M" << std::endl;
	}
	
	
	std::cout << std::endl; //dialog
	std::cout << "Implied size" << std::endl; //dialog
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_2[i] << "M" << std::endl;
		continue;
	}
	"\n";

	int myNumbers[] = { 10, 20 , 30, 40, 50 };
	for (int i = 0; i <= sizeof(myNumbers[0]); i++)
	{
		std::cout << myNumbers[i] << std::endl;
		
	};
	std::cout << "\n";

	//Range-based for loop







	std::cout << "\n";
}

void DynamicArrays()
{


	int* numbers = new int[5];
	int differentNumbers = 3;
	int *anotherSetOfNumbers = new int[differentNumbers];
	int* dereference = &differentNumbers;

	for (int i = 0; i < differentNumbers; i++)
	{

		std::cout << differentNumbers << "\n";
	}
	std::cout << anotherSetOfNumbers << "\n";
	
	std::cout << dereference << "\n";


	delete[] numbers;
	delete[] anotherSetOfNumbers;

}

void MultiDimArrays()
{
	// 2x2 array of integers
	int gridArray[2][2];

	// using an initializer list
	int gridWithNumbers[2][2] = { { 1,3 }, { 2,4 } };

	std::cout << "\n";
	std::cout << "Multi Dimensional Array" << std::endl;
	/*
	for (int i = 0; i <= gridWithNumbers[i][i]; i++)
	{
		std::cout << gridWithNumbers[i][i] << std::endl;
	}*/

	//-----------------
	/*for (int i = 0; i < gridWithNumbers[i][i]; i++)
	{
		
		for (int j = 0; j < gridWithNumbers[j][j]; j++)
		{
			std::cout << gridWithNumbers[i][j] << std::endl;

		}
	}*/
}