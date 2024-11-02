#include <iostream>
#include <string>

static void Arrays();

void main()
{
	Arrays();
};

void Arrays()
{
	const int anArray = 3;
	int* moreNumber[anArray];

	for (int i = 0; i < anArray; i++)
	{
		std::cout << moreNumber[anArray] << std::endl;
	}
}