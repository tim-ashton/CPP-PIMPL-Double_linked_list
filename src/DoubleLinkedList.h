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
	class ListImpl;						//Forward declaration
	std::shared_ptr<ListImpl> pImpl;	//Pointer to the implementation.
public:
	DoubleLinkedList();
	virtual ~DoubleLinkedList();
};

#endif /* DOUBLELINKEDLIST_H_ */