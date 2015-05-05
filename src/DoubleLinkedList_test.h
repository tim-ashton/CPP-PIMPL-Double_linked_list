/*
 * DoubleLinkedList_test.cpp
 *
 *  Created on: 21/04/2015
 *      Author: Tim Ashton
 */

#ifndef DOUBLELINKEDLIST_TEST_H_
#define DOUBLELINKEDLIST_TEST_H_

#include "DoubleLinkedList.h"
#include <limits.h>
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

	assert(d.GetCurrentVal() == d2.GetCurrentVal());

	while(++d && ++d2)
	{
		assert(d.GetCurrentVal() == d2.GetCurrentVal());
	}

	assert(d.Back() == d2.GetCurrentVal());
}

void TestSize()
{
	DoubleLinkedList d;

	for(int i = 0; i < 10; i++)
	{
		d.Insert(i);
		assert(d.Size() == (i+1));
	}

	for(int i = 10; i < 20; i++)
	{
		d.Insert(i);
		assert(d.Size() == (i+1));
	}

	for(int i = 19; i > 9; i--)
	{
		d.Remove(i);
		std::cout << d.Size() << std::endl;
		//assert(d.Size() == (i));
	}

	for(int i = 9; i >= 0; i--)
	{
		d.Remove(i);
		assert(d.Size() == (i));
	}
}

void TestInsert()
{
	DoubleLinkedList d;

	// insert 1 element
	d.Insert(5);

	assert(d.Size() == 1);
	assert(d.Back() == d.Front());
	assert(d.Front() == 5);

	// insert another element
	d.Insert(56);
	assert(d.Size() == 2);
	assert(d.Front() != d.Back());
	assert(d.Front() == 5);

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	assert(d.Size() == 102);
	assert(d.Front() != d.Back());
	assert(d.Front() == 5);
	assert(d.Back() == 99);

	int count = 0;
	while(++d && ++ count);
	assert(count == 101); // 0 indexed

	assert(d.GetCurrentVal() == 99);
}

void TestRemove()
{
	DoubleLinkedList d;

	// insert 1 element
	d.Insert(5);
	d.Remove(5);

	assert(d.Size() == 0);
	assert(d.Back() == d.Front());
	assert(d.Front() == INT_MIN);

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}
	for(int i = 0; i < 50; i++)
	{
		d.Remove(i);
	}

	assert(d.Front() == 50);
	assert(d.Size() == 50);

}


void TestEmpty()
{
	//TODO
}

#endif // DOUBLELINKEDLIST_TEST_H_
