#pragma once
class DoubleLinkedList
{
public:
	class Node
	{
	public:
		int data;
		Node* previous;
		Node* next;

	};

	Node* head = nullptr;
	Node* tail = nullptr;

	void pushFront(int value);

	void pushBack(int value);

	void insert(int value, Node*)
	{

	}
	Node* begin();

	Node* end();
	
	int& first();

	int& last();

	int count();

	void erase(Node*)
	{

	}
	void remove(int value)
	{

	}
	void popBack()
	{

	}
	void popFront();
	bool empty();

	void clear();
};