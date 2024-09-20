#include <iostream>
#include <string>





static void FixedArrays();
{
	float distanceMeasurements[3];

	//Initailise List size
	float measurementsM_1[3] = { 1.2f, 2.5f, 3.7f };
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_1[i] << "M" << std::endl;
	}
	std::cout << std::endl;

	//Implied size
	float measurementsM_2[] = { 1.2f, 2.5f, 3.7f };
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_2[i] << "M" << std::endl;

	}
}

//Declareing Arrays - fixed sized
void main()
{
	float distanceMeasurements[3];

	//Initailise List size
	float measurementsM_1[3] = { 1.2f, 2.5f, 3.7f };
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_1[i] << "M" << std::endl;
	}
	std::cout << std::endl;
	
	//Implied size
	float measurementsM_2[] = { 1.2f, 2.5f, 3.7f };
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_2[i] << "M" << std::endl;

	}
}

