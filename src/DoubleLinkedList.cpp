/*
 * DoubleLinkedList.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Tim Ashton
 */

#include "DoubleLinkedList.h"

class DoubleLinkedList::ListImpl
{
	struct Node
	{
		Node(int input)
			:data(input)
		{}

		int data;
		Node *next;
		Node *previous;
	};

	Node *firstNode;
	Node *lastNode;
	int listSize;

public:
	ListImpl()
	{
		firstNode = NULL;
		lastNode = NULL;
	}

	~ListImpl();

	int Size

	/*
	 * insert()
	 *
	 * inserts a new node populated with input data in the
	 * correct location in the list. Maintains ordering of
	 * list.
	 */
	void Insert(int input)
	{
		if(!firstNode)
		{
			firstNode = new Node(input);
			lastNode = firstNode;
		}
		else
		{
			// Find the location to insert the node.
		}
	}
};

DoubleLinkedList::DoubleLinkedList()
	: pImpl(new ListImpl())
{}

DoubleLinkedList::~DoubleLinkedList()
{
	// Do nothing. Let the shared_ptr handle deallocation.
}

