/*
 * DoubleLinkedList_test.cpp
 *
 *  Created on: 21/04/2015
 *      Author: tim
 */

#include "DoubleLinkedList.h"

bool TestInsertOne()
{
	DoubleLinkedList dLink;

	// insert 1 element
	dLink.Insert(5);
	if(dLink.Size() != 1)
	{
		return false;
	}
	else if (dLink.Front() != dLink.Back())
	{
		return false;
	}
	else if (dLink.Front() != 5)
	{
		return false;
	}

	// insert another element
	dLink.Insert(56);
	if(dLink.Size() != 2)
	{
		return false;
	}
	else if (dLink.Front() == dLink.Back())
	{
		return false;
	}
	else if (dLink.Front() != 5)
	{
		return false;
	}
	else if (dLink.Front() != 5)
	{
		return false;
	}

	return true;
}

bool TestInsertTwo()
{
	DoubleLinkedList dLink;

	// insert 2 elements
	dLink.Insert(5);
	dLink.Insert(56);
	if(dLink.Size() != 2)
	{
		return false;
	}
	else if (dLink.Front() == dLink.Back())
	{
		return false;
	}
	else if (dLink.Front() != 5)
	{
		return false;
	}
	else if (dLink.Back() != 56)
	{
		return false;
	}

	return true;
}
