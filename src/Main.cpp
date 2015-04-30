//============================================================================
// Name        : CPP-PIMPL-Double_linked_list.cpp
// Author      : Tim Ashton
// Version     :
// Copyright   : No Copyright
// Description : C++, Ansi-style
//============================================================================

#include <iostream>

#include "DoubleLinkedList.h"

int main() {

	DoubleLinkedList d;

	d.Insert(5);
	d.Insert(4);
	d.Insert(3);
	d.Insert(7);
	d.Insert(-1);



	int curr = d.GetCurrentVal();
	std::cout << curr << std::endl;
	while(++d)
	{
		std::cout << d.GetCurrentVal() << std::endl;
	}
	std::cout << std::endl;
	std::cout << d.GetCurrentVal() << std::endl;
	while(--d)
	{
		std::cout << d.GetCurrentVal() << std::endl;
	}
	std::cout << std::endl;
	d.Remove(3);
	d.Remove(-1);

	d.CurrentToFront();
	std::cout << curr << std::endl;
	while(++d)
	{
		std::cout << d.GetCurrentVal() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
