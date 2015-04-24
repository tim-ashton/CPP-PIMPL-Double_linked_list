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
	* Inserts a new node populated with input data in the list.
	*/
	void Insert(int input)
	{
		std::shared_ptr<Node> newNode(new Node(input));
		lastNode = newNode;

		if (listSize == 0) //insert into an empty list
		{
			firstNode = newNode;
			listSize++;
		}
		else if(listSize == 1)
		{
			firstNode->next = newNode;
			newNode->previous = firstNode;
			listSize++;
		}
		else
		{
			firstNode = Insert(newNode, firstNode->next);
		}
	}

	int Back()
	{
		return lastNode->data;
	}

	int Front()
	{
		return firstNode->data;
	}

private:

	/*
	* Insert()
	*
	* This is a recursive insert on the list.
	* Note: There is absolutely no need for recuresion. In fact this would be more
	* memory economic to just use a loop.
	*
	* I just wanted to use recursion for fun...
	*/
	std::shared_ptr<Node> Insert(std::shared_ptr<Node> newNode, std::shared_ptr<Node> head)
	{
		if (!head->next)
		{
			head->next = newNode;
			newNode->previous = head;
			listSize++;
		}
		else
		{
			head = Insert(newNode, head->next);
		}
		return head->previous;
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

int DoubleLinkedList::Back()
{
	return pImpl->Back();
}

int DoubleLinkedList::Front()
{
	return pImpl->Front();
}

