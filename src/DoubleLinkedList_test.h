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
	assert(d.Size() == 51);
	assert(d.Back() == 500);

	DoubleLinkedList d2(d);

	assert(d.Size() == d2.Size());
	assert(d.Back() == d2.Back());
	assert(d.Front() == d2.Front());
	assert(&d != &d2);

	int dCurr = d.GetCurrentVal();
	int d2Curr = d2.GetCurrentVal();
	assert(dCurr == d2Curr);

//	while(++d && ++d2)
//	{
//		assert()
//	}
}

bool TestInsert()
{
	DoubleLinkedList d;

	// insert 1 element
	d.Insert(5);

	assert(d.Size() == 1);
	assert(d.Back() == d.Front());
	assert(d.Front() == 5);

	// insert another element
//	dLink.Insert(56);
//	if(dLink.Size() != 2)
//	{
//		return false;
//	}
//	else if (dLink.Front() == dLink.Back())
//	{
//		return false;
//	}
//	else if (dLink.Front() != 5)
//	{
//		return false;
//	}
//	else if (dLink.Front() != 5)
//	{
//		return false;
//	}

	return true;
}



#endif // DOUBLELINKEDLIST_TEST_H_
