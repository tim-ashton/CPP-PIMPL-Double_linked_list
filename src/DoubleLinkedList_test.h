/*
 * DoubleLinkedList_test.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Tim Ashton
 */

#ifndef DOUBLELINKEDLIST_TEST_H_
#define DOUBLELINKEDLIST_TEST_H_

#include "DoubleLinkedList.h"
#include <assert.h>
#define NDEBUG

void TestDefaultConstructor()
{
	DoubleLinkedList dLink;
    assert(dLink.Size() == 0);
    assert(dLink.Empty());
    assert(!++dLink);
    assert(!--dLink);
}

void TestCopyConstructor()
{
	DoubleLinkedList d;

	for(int i = 0; i < 501; i++)
	{
		if(i%10 == 0)
		{
			d.Insert(i);
		}
	}
	int x = d.Back();
	assert(d.Size() == 51);
	assert(d.Back() == 500);
}

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

#endif // DOUBLELINKEDLIST_TEST_H_
