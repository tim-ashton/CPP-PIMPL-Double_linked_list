//============================================================================
// Name        : CPP-PIMPL-Double_linked_list.cpp
// Author      : Tim Ashton
// Version     :
// Copyright   : No Copyright
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	
	DoubleLinkedList d;

	d.Insert(5);
	d.Insert(10);
	d.Insert(3);
	d.Insert(7);
	d.Insert(-1);

	int x = d.Size();
	return 0;
}
