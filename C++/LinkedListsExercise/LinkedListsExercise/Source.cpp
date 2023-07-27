#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

void main()
{
	DoubleLinkedList list;

	list.pushBack(4);
	list.pushBack(1);
	list.pushBack(8);
	list.pushBack(7);
	list.pushBack(5);
	
	for (DoubleLinkedList::Node* pos = list.begin(); pos != list.end(); pos = pos->next)
	{
		std::cout << pos->data << std::endl;


	}
	
}