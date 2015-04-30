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
		Node *next;
		Node *previous;

		Node(int input)
		: data(input)
		, next(nullptr)
		, previous(nullptr)
		{}
	};

	int listSize;
	Node *first;
	Node *last;
	Node *current;


public:
	ListImpl()
	: listSize(0)
	, first(nullptr)
	, last(nullptr)
	, current(nullptr)
	{}

	ListImpl(const ListImpl &rhs)
	: listSize(0)
	, first(nullptr)
	, last(nullptr)
	, current(nullptr)
	{
		Node* temp = rhs.first;
		while(temp)
		{
			this->Insert(temp->data);
			temp = temp->next;
		}
	}

	~ListImpl()
	{
		ClearList();
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
	 * Insert()
	 *
	 * Inserts a new node populated with input data in the list.
	 */
	void Insert(int input)
	{
		Node *newNode = new Node(input);
		last = newNode;

		if (listSize == 0) //insert into an empty list
		{
			first = newNode;
			current = first;
			listSize++;
		}
		else if (listSize == 1)
		{
			first->next = last;
			last->previous = first;
			listSize++;
		}
		else
		{
			first = Insert(newNode, first->next);
		}
	}

	/*
	 * Remove
	 *
	 * Removes the node(s) where value matches node data.
	 */
	void Remove(int value)
	{
		if (listSize == 0)
		{
			return;
		}
		else if (listSize == 1)
		{
			if (first->data == value)
			{
				delete first;
				first = last = nullptr;
				listSize--;
			}
			else
			{
				return;
			}
		}
		else
		{
			first = Remove(value, first->next);
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
	 * Return value of data in the last node in the list.
	 */
	int Back()
	{
		return last->data;
	}

	/*
	 * Return value of data in the first node in the list.
	 */
	int Front()
	{
		return first->data;
	}


	int GetCurrentVal()
	{
		return current->data;
	}

	void SetCurrentVal(int value)
	{
		current->data = value;
	}

	void CurrentToFront()
	{
		current = first;
	}

	void CurrentToBack()
	{
		current = last;
	}

	void ClearList()
	{
		current = nullptr;
		last = nullptr;
		while(first)
		{
			if(first->next)
			{
				first = first->next;
				delete first->previous;
				first->previous = nullptr;
			}
			else
			{
				delete first;
				first = nullptr;
			}

		}
	}

	bool operator ++()
																	{
		if(current->next)
		{
			current = current->next;
			return true;
		}
		return false;
																	}

	bool operator --()
																	{
		if(current->previous)
		{
			current = current->previous;
			return true;

		}
		return false;
																	}

private:

	/*
	 * Insert()
	 *
	 * Recursive insert on the list.
	 */
	Node *Insert(Node *newNode, Node *head)
	{
		if (!(head->next))
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
	Node *Remove(int value, Node *toRemove)
	{
		if (toRemove->data == value) //remove head
		{
			toRemove->previous->next = toRemove->next;
			if (toRemove == last)
			{
				// have reached the end move "last" back one node.
				last = toRemove->previous;
			}
			else
			{
				// Somewhere else in the list
				toRemove->next->previous = toRemove->previous;
			}
			listSize--;
			delete toRemove;
		}
		else
		{
			Remove(value, toRemove->next);
		}
		return toRemove->previous;
	}
};



DoubleLinkedList::DoubleLinkedList()
: pImpl(new ListImpl())
{}

DoubleLinkedList::~DoubleLinkedList()
{} // Do nothing. Let the unique_ptr handle deallocation.

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

int DoubleLinkedList::GetCurrentVal()
{
	return pImpl->GetCurrentVal();
}

void DoubleLinkedList::SetCurrentVal(int value)
{
	pImpl->SetCurrentVal(value);
}

void DoubleLinkedList::CurrentToFront()
{
	pImpl->CurrentToFront();
}

void DoubleLinkedList::CurrentToBack()
{
	pImpl->CurrentToBack();
}

void DoubleLinkedList::ClearList()
{
	pImpl->ClearList();
}

bool DoubleLinkedList::operator ++()
{
	return ++*pImpl.get();
}

bool DoubleLinkedList::operator --()
{
	return --*pImpl.get();
}



