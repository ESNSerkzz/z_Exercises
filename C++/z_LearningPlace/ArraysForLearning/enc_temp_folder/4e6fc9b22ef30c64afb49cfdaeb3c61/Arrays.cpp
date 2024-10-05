#include "Arrays.h"
#include <iostream>
#include <string>

void FixedArrays();
void DynamicArrays();


void main()
{
	FixedArrays();
	DynamicArrays();
}

//Declareing Arrays - fixed sized
void FixedArrays()
{
	float distanceMeasurements[3];

	//Initailise List size
	float measurementsM_1[3] = { 1.2f, 2.5f, 3.7f };
	//Implied size
	float measurementsM_2[] = { 1.2f, 2.5f, 3.7f };

	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_1[i] << "M" << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_2[i] << "M" << std::endl;
	}
}

void DynamicArrays()
{
	int* numbers = new int[5];

	int lengthOfNumbers = 10;

	int* anotherSetOfNumbers = new int[lengthOfNumbers];

	delete[] numbers;
	delete[] anotherSetOfNumbers;
	
	
	

}

