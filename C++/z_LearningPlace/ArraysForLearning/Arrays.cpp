
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
	float measurementsM_2[] = { 2.2f, 4.5f, 6.7f };



	std::cout << "Fixed sized arrays" << std::endl;
	std::cout << "Initialised List size" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_1[i] << "M" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Implied size" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << measurementsM_2[i] << "M" << std::endl;
	}
	int myNumbers[] = { 10, 20 , 30, 40, 50 };
	for (int i = 0; i < sizeof(myNumbers) / sizeof(myNumbers[0]); i++)
	{
		std::cout << "\n" << myNumbers[i];
	};
}

void DynamicArrays()
{


	int* numbers = new int[5];
	int differentNumbers = 3;
	int* anotherSetOfNumbers = new int[differentNumbers];
	void* ptr;


	std::cout << anotherSetOfNumbers << "\n";
	
	
	delete[] numbers;
	delete[] anotherSetOfNumbers;

}

