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
		int data;
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> previous;

		Node(int input)
			:data(input)
			, next(NULL)
			,previous(NULL)
		{}
	};

	std::shared_ptr<Node> firstNode;
	std::shared_ptr<Node> lastNode;
	int listSize;

public:
	ListImpl()
	{
		firstNode = NULL;
		lastNode = NULL;
		listSize = 0;
	}

	~ListImpl()
	{} // Let the shared_ptr handle delete.

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
	* Insert()
	*
	* Inserts a new node populated with input data in the
	* correct location in the list. Maintains ordering of list.
	* If an attempt to insert a value that already resides in
	* the list insert will insert in the front of existing node(s).
	*/
	void Insert(int input)
	{
		std::shared_ptr<Node> newNode(new Node(input));

		if (!firstNode.get()) //insert into an empty list
		{
			firstNode = newNode;
			lastNode = newNode;
			listSize++;
		}
		else
		{
			Insert(newNode, firstNode);
		}
	}

private:
	/*
	* Insert()
	*
	* This is the recursive insert on the list.
	* Note: There is absolutely no need for recuresion. In fact this would be more 
	* econimic to just us a while loop. 
	* 
	* I just wanted to use recursion for fun...
	*/
	void Insert(std::shared_ptr<Node> newNode, std::shared_ptr<Node> next)
	{
		if (newNode->data < next->data)
		{
			Insert(newNode, next->next);
		}
		else
		{
			newNode->next = next;
			newNode->previous = next->previous;
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

