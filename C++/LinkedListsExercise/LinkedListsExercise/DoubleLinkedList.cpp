#include "DoubleLinkedList.h"
#include <cassert>


void DoubleLinkedList::pushFront(int value)
{
	Node* newNode = new Node{ value , nullptr, head};
	if (head != nullptr)
	{
		head->previous = newNode;

	}
	else
	{
		tail = newNode;
	}

	head = newNode;
}

void DoubleLinkedList::pushBack(int value)
{
	Node* newNode = new Node{ value ,tail , nullptr };
	if (head != nullptr)
	{
		tail->next = newNode;

	}
	else
	{
		head = newNode;
	}

	tail = newNode;
}

DoubleLinkedList::Node* DoubleLinkedList::begin()
{
	return head;
}

DoubleLinkedList::Node* DoubleLinkedList::end()
{
	return nullptr;
}

int& DoubleLinkedList::first()
{
	assert(head != nullptr);
	
	
	return head->data;
}

int& DoubleLinkedList::last()
{
	assert(tail != nullptr);

	return tail->data;
}

int DoubleLinkedList::count()
{
	int count = 0;

	for (DoubleLinkedList::Node* pos = begin(); pos != end(); pos = pos->next)
	{
		count++;

	}
	return count;
}


// popFront// using the logic following from the pushFront. knock off or delete the value at the front
inline void DoubleLinkedList::popFront()
{
	
}

bool DoubleLinkedList::empty()
{
	return (count() == 0);

}

void DoubleLinkedList::clear()
{
	Node* loc = begin();
	while (loc != nullptr)
	{
		Node* target = loc;
		loc = loc->next;
		delete target;
	}

	head = nullptr;
	tail = nullptr;
}