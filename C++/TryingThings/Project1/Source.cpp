#include <iostream>
#include <string>
#pragma once


void PassByReference(int&);

int main()
{
	//std::cout << "hello, world?" << std::endl;

	/*std::string myString;
	std::string name = "John";
	myString = name;
	std::cout << myString << std::endl;*/

	/*std::string name = "bobalina";
	int length = name.length();
	std::cout << name << std::endl;
	std::cout << length << std::endl;*/

	/*std::string name1 = "John";
	std::string name2 = "bob";

	std::cout << name1 << ", " << name2 << std::endl;


	if (name1 == name2)
	{
		std::string text = "they're the same";
		std::cout << text << std::endl;
	}
	else
	{
		std::string text = "Do they look the same to you?";
		std::cout << text << std::endl;
	}*/

	/*const int numbers_length = 5;
	int nums[numbers_length] = { 1,3,5,7,9 };

	std::cout << nums << std::endl;

	for (int val : nums)
	{
		std::cout << val << std::endl;
	}*/

	int myValue = 10;
	PassByReference(myValue);

	std::cout << myValue << std::endl;
	system("pause");
}
void PassByReference(int &myValue)
{
	myValue *= 2; // Does not modify the variable passed in!
	std::cout << myValue << std::endl;
}