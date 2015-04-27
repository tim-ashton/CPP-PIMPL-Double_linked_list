/*
 * DoubleLinkedList.cpp
 *
 * Contains private list implementation.
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
		, previous(NULL)
		{}
	};


	template <typename T> class ListIterator
	: std::iterator< std::bidirectional_iterator_tag, T >
	{
		// iterator class definition goes here
	};

	typedef ListIterator<Node*> iterator_type;
	//typedef MyIterator<const int*> const_iterator_type

	std::shared_ptr<Node> firstNode;
	std::shared_ptr<Node> lastNode;
	int listSize;

public:
	ListImpl()
	{
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
		else if (listSize == 1)
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

	/*
	 * Remove
	 *
	 * Removes the node(s) where value matches node data.
	 */
	void Remove(int value)
	{
		if (!firstNode)
		{
			return;
		}
		else if (!firstNode->next)
		{
			if (firstNode->data == value)
			{
				firstNode.reset();
				lastNode.reset();
				listSize--;
			}
			else
			{
				return;
			}
		}
		else
		{
			firstNode = Remove(value, firstNode->next);
		}
	}

	/*
	 *Empty
	 *
	 * Return true if the container size is 0, false otherwise.
	 */
	bool Empty()
	{
		return (listSize == 0);
	}

	/*
	 * Back
	 *
	 * Return value of data in the last node in the list.
	 */
	int Back()
	{
		return lastNode->data;
	}

	/*
	 * Return value of data in the first node in the list.
	 */
	int Front()
	{
		return firstNode->data;
	}

private:

	/*
	 * Insert()
	 *
	 * Recursive insert on the list.
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

	/*
	 * Remove
	 *
	 * Recursive helper function to remove a node in the list.
	 */
	std::shared_ptr<Node> Remove(int value, std::shared_ptr<Node> head)
					{
		if(head->data == value) //remove head
		{
			head->previous->next = head->next;
			if(head == lastNode)
			{
				lastNode = head->previous;
			}
			else
			{
				head->next->previous = head->previous;
			}
			listSize--;
			// Let head go out of scope so shared_ptr
			// can call the delete as necessary.
		}
		else
		{
			Remove(value, head->next);
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

void DoubleLinkedList::Remove(int value)
{
	pImpl->Remove(value);
}

bool DoubleLinkedList::Empty()
{
	return pImpl->Empty();
}

int DoubleLinkedList::Back()
{
	return pImpl->Back();
}

int DoubleLinkedList::Front()
{
	return pImpl->Front();
}


