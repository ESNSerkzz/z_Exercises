#include <iostream>
#include <string>

class ShallowClass
{
public:
	ShallowClass();
	ShallowClass(int value);
	~ShallowClass();


	void print();

	void setValue(int value) { *m_data = value; }

private:
	int* m_data;
};
ShallowClass::ShallowClass()
{
	m_data = new int[5] {0,1,2,3,4};
}

ShallowClass::ShallowClass(int value)
{
	m_data = new int(value);
}

ShallowClass::~ShallowClass()
{
	if (m_data != nullptr)
		//delete m_data;
	m_data = nullptr;
}

void ShallowClass::print()
{
	std::cout << "Value " << *m_data << ", at memory location " << m_data << std::endl;
}


//-------------------------------------------------------------------------------------------------------------------

class DeepClass
{
public:
	DeepClass();
	DeepClass(int value);
	DeepClass(const DeepClass& other);
	~DeepClass();

	DeepClass& operator= (const DeepClass& other);

	void print();

	void setValue(int value) { *m_data = value; }

private:
	int* m_data;
};


DeepClass::DeepClass() {
	m_data = new int(0);
}

DeepClass::DeepClass(int value) {
	m_data = new int(value);
}

DeepClass::DeepClass(const DeepClass& other) {
	std::cout << "Performing deep copy in copy constructor" << std::endl;
	m_data = new int(*other.m_data);
}

DeepClass::~DeepClass() {
	delete m_data;
}

DeepClass& DeepClass::operator= (const DeepClass& other) {
	std::cout << "Performing deep copy in assignment operator" << std::endl;
	*m_data = *other.m_data;
	return *this;
}

void DeepClass::print() {
	std::cout << "Value " << *m_data << ", at memory location " << m_data << std::endl;
}

int main()
{
	/*ShallowClass shallow1(10);
	ShallowClass shallow2 = shallow1;
	ShallowClass shallow3;

	shallow3 = shallow1;

	shallow1.setValue(27);

	shallow1.print();
	shallow2.print();
	shallow3.print();*/

	DeepClass deep1(15);
	DeepClass deep2 = deep1;
	DeepClass deep3;

	deep3 = deep1;

	deep1.print();
	deep2.print();
	deep3.print();
	//deep1.setValue(27);
}