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
		listSize = 0;
	}

	~ListImpl()
	{
		// TODO
	}

	/*
	* int Size()
	* 
	* Return the number of nodes in the list.
	*/
	int Size()
	{
		return listSize;
	}

	/*
	* insert()
	*
	* Inserts a new node populated with input data in the
	* correct location in the list. Maintains ordering of
	* list.
	*/
	void Insert(int input)
	{
		if (!firstNode)
		{
			firstNode = new Node(input);
			lastNode = firstNode;
			listSize++;
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


int DoubleLinkedList::Size()
{
	return pImpl->Size();
}

void DoubleLinkedList::Insert(int input)
{
	pImpl->Insert(input);
}

