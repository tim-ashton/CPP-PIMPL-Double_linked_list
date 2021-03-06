/*
 * DoubleLinkedList.cpp
 *
 * Contains private list implementation.
 *
 *  Created on: 21/04/2015
 *      Author: Tim Ashton
 */


#include "DoubleLinkedList.h"
#include <limits.h>

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

	ListImpl(const ListImpl *rhs)
	: listSize(0)
	, first(nullptr)
	, last(nullptr)
	, current(nullptr)
	{
		Node* temp = rhs->first;
		while(temp)
		{
			this->Insert(temp->data);
			temp = temp->next;
		}
	}

	~ListImpl() { ClearList(); }

	int Size() { return listSize; }

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

	bool Remove(int value)
	{
		if (listSize == 0)
		{
			return false;
		}
		else if (listSize == 1)
		{
			if (first->data == value)
			{
				delete first;
				first = last = current = nullptr;
				listSize--;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			// Check if it is the first item in the list
			if (first->data == value)
			{
				Node *temp = first;
				first = first->next;
				first->previous = nullptr;

				if(current == temp) // current was pointing at temp so move it too
				{
					current = first;
				}

				delete temp;
				listSize--;
				return true;
			}
			else
			{
				return Remove(value, first->next);
			}
		}
	}

	bool Empty() { return (listSize == 0); }

	int Back()
	{
		if(last)
		{
			return last->data;
		}
		return INT_MIN;
	}

	int Front()
	{
		if(first)
		{
			return first->data;
		}
		return INT_MIN;
	}

	int GetCursorVal()
	{
		if(current)
		{
			return current->data;
		}
		return INT_MIN;
	}


	bool SetCursorVal(int value)
	{
		if(current)
		{
			current->data = value;
			return true;
		}
		return false;
	}

	void CursorToFront() { current = first; }

	void CursorToBack() { current = last; }

	void ClearList()
	{
		current = nullptr;
		last = nullptr;
		listSize = 0;
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
		if(!current)
		{
			return false;
		}
		else if(current->next)
		{
			current = current->next;
			return true;
		}
		return false;
			}

	bool operator --()
			{
		if(!current)
		{
			return false;
		}
		else if(current->previous)
		{
			current = current->previous;
			return true;

		}
		return false;
			}

private:

	/* Insert()
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

	/* Remove ()
	 *
	 * Recursive helper function to remove a node in the list.
	 */
	bool Remove(int value, Node *toRemove)
	{
		if (toRemove->data == value) //remove toRemove
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
			toRemove = nullptr;
			return true;
		}
		else
		{
			return Remove(value, toRemove->next);
		}
	}
};

DoubleLinkedList::DoubleLinkedList()
: pImpl(new ListImpl())
{}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &rhs)
: pImpl(new ListImpl(rhs.pImpl.get()))
{}

// Do nothing. Let the unique_ptr handle deallocation.
DoubleLinkedList::~DoubleLinkedList() {}

int DoubleLinkedList::Size() { return pImpl->Size(); }

void DoubleLinkedList::Insert(int input) { pImpl->Insert(input); }

bool DoubleLinkedList::Remove(int value) { return pImpl->Remove(value); }

bool DoubleLinkedList::Empty() { return pImpl->Empty(); }

int DoubleLinkedList::Back() { return pImpl->Back(); }

int DoubleLinkedList::Front() {	return pImpl->Front(); }

int DoubleLinkedList::GetCursorVal() {	return pImpl->GetCursorVal(); }

bool DoubleLinkedList::SetCursorVal(int value) { return pImpl->SetCursorVal(value); }

void DoubleLinkedList::CursorToFront() { pImpl->CursorToFront(); }

void DoubleLinkedList::CursorToBack() { pImpl->CursorToBack(); }

void DoubleLinkedList::ClearList() { pImpl->ClearList(); }

bool DoubleLinkedList::operator ++() { return ++*pImpl.get(); }

bool DoubleLinkedList::operator --() { return --*pImpl.get(); }



