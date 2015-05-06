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

/*
 * Skipping tests for Front() and Back() as they are used
 * extensively throughout the other tests.
 */

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

	assert(d.GetCursorVal() == d2.GetCursorVal());

	while(++d && ++d2)
	{
		assert(d.GetCursorVal() == d2.GetCursorVal());
	}

	assert(d.Back() == d2.GetCursorVal());
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
		assert(d.Size() == (i));
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

	assert(d.GetCursorVal() == 99);
}

void TestRemove()
{
	DoubleLinkedList d;

	// insert 1 element
	d.Insert(5);
	assert(d.Remove(5));

	assert(d.Size() == 0);
	assert(d.Back() == d.Front());
	assert(d.Front() == INT_MIN);

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}
	for(int i = 0; i < 50; i++)
	{
		assert(d.Remove(i));
	}

	assert(d.Front() == 50);
	assert(d.Size() == 50);
	assert(d.Back() == 99);

	assert(d.Remove(d.Back()));
}


void TestEmpty()
{
	DoubleLinkedList d;
	assert(d.Empty());

	d.Insert(1);
	assert(!d.Empty());

	d.Remove(1);
	assert(d.Empty());
}

void TestGetCursorVal()
{
	DoubleLinkedList d;
	assert(d.GetCursorVal() == INT_MIN);

	d.Insert(1);
	assert(d.GetCursorVal() == 1);

	d.Remove(1);
	assert(d.GetCursorVal() == INT_MIN);

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	assert(d.GetCursorVal() == 0);

	// move cursor to the back
	while(++d);
	assert(d.GetCursorVal() == d.Back());

	// move cursor back to the front
	while(--d);
	assert(d.GetCursorVal() == d.Front());

	d.CursorToBack();
	assert(d.GetCursorVal() == d.Back());

	d.CursorToFront();
	assert(d.GetCursorVal() == d.Front());
}

void TestSetCurserVal()
{
	DoubleLinkedList d;
	assert(!d.SetCursorVal(1));

	d.Insert(1);
	assert(d.SetCursorVal(5));
	assert(d.Front() == 5);

	assert(d.Remove(5));
	assert(!d.SetCursorVal(1));

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	d.CursorToBack();

	d.SetCursorVal(-99);
	while(--d)
	{
		d.SetCursorVal(-99);
	}

	assert(d.Front() == -99);
	while(++d)
	{
		assert(d.GetCursorVal() == -99);
	}
}

void TestCursorToFront()
{
	DoubleLinkedList d;

	d.CursorToFront();
	assert(d.GetCursorVal() == d.Front());
	assert(d.GetCursorVal() == d.Back());

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	while(++d); // moves the cursor to the end
	assert(d.GetCursorVal() != d.Front());

	d.CursorToFront();
	assert(d.GetCursorVal() == d.Front());
}

void TestCursorToBack()
{
	DoubleLinkedList d;

	d.CursorToBack();
	assert(d.GetCursorVal() == d.Front());
	assert(d.GetCursorVal() == d.Back());

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	d.CursorToBack();
	assert(d.GetCursorVal() == d.Back());
	assert(d.GetCursorVal() != d.Front());

	while(--d);
	assert(d.GetCursorVal() != d.Back());

	d.CursorToBack();
	assert(d.GetCursorVal() == d.Back());
	assert(d.GetCursorVal() != d.Front());
}

void TestClearList()
{
	DoubleLinkedList d;

	d.ClearList();
	assert(d.Back() == d.Front());

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	d.ClearList();

	assert(d.Size() == 0);
	assert(!d.SetCursorVal(1));
	assert(d.Back() == d.Front());
}

void TestPrePlusPlus()
{
	DoubleLinkedList d;

	assert(!++d);

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	while(++d);

	assert(d.GetCursorVal() == d.Back());

	d.CursorToFront();

	while(++d);
	assert(d.GetCursorVal() == d.Back());
}

void TestPreMinusMinus()
{
	DoubleLinkedList d;

	assert(!--d);

	for(int i = 0; i < 100; i++)
	{
		d.Insert(i);
	}

	while(++d);
	while(--d);

	assert(d.GetCursorVal() == d.Front());

	d.CursorToBack();
	assert(d.GetCursorVal() == d.Back());

	assert(d.Remove(d.GetCursorVal()));
	while(--d)
	{
		assert(d.Remove(d.GetCursorVal()));
	}

	assert(d.Size() == 0);

	assert(!--d);
}

#endif // DOUBLELINKEDLIST_TEST_H_
