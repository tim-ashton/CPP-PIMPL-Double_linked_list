/*
 * DoubleLinkedList.h
 *
 *  Created on: 21/04/2015
 *      Author: Tim Ashton
 *
 *	An ordered doubly linked list implemented using PIMPL idiom.
 *
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <memory>

class DoubleLinkedList
{
	class ListImpl;						//Forward declare
	std::unique_ptr<ListImpl> pImpl;	//Pointer to the implementation.

public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList &rhs);
	virtual ~DoubleLinkedList();

	/* Size()
	 *
	 * Return the number of nodes in the list.
	 */
	int Size();

	/* Insert()
	 *
	 * Inserts a new node populated with input data in the list.
	 */
	void Insert(int input);

	/* Remove()
	 *
	 * Removes the node(s) where value matches node data.
	 */
	void Remove(int value);

	/* Empty()
	 *
	 * Return true if the container size is 0, false otherwise.
	 */
	bool Empty();

	/* Front()
	 *
	 * Return value of data in the first node in the list.
	 */
	int Front();

	/* Back()
	 *
	 * Return value of data in the last node in the list.
	 */
	int Back();

	/* GetCurrentVal()
	 *
	 * Gets the value of where the current cursor points.
	 */
	int GetCurrentVal();

	/* SetCurrentVal()
	 *
	 * Sets the value of where the current cursor points to
	 * parameter value.
	 */
	void SetCurrentVal(int value);

	/* CurrentToFront()
	 *
	 * Points the current cursor to the front of the list (Node *first).
	 */
	void CurrentToFront();

	/*CurrentToBack()
	 *
	 * Points the current cursor to the back of the list (Node *last).
	 */
	void CurrentToBack();

	/* ClearList()
	 *
	 * Destroys all nodes. Returns the list back to state of default
	 * constructor.
	 */
	void ClearList();

	/* operator ++()
	 *
	 * Advance the cursor (Node * current) one node.
	 */
	bool operator ++();

	/* operator --()
	 *
	 * Reverse the cursor (Node * current) one node.
	 */
	bool operator --();

};
#endif /* DOUBLELINKEDLIST_H_ */
