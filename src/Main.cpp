//============================================================================
// Name        : CPP-PIMPL-Double_linked_list.cpp
// Author      : Tim Ashton
// Version     :
// Copyright   : No Copyright
// Description : C++, Ansi-style
//============================================================================

#include <iostream>

#include "DoubleLinkedList.h"
#include "DoubleLinkedList_test.h"

int main()
{
	try
	{
		TestDefaultConstructor();
		std::cout << "TestDefaultConstructor passed." << std::endl;

		TestCopyConstructor();
		std::cout << "TestCopyConstructor passed." << std::endl;

		TestInsert();
		std::cout << "TestInsert passed." << std::endl;

		TestSize();
		std::cout << "TestSize passed." << std::endl;

		TestRemove();
		std::cout << "TestRemove passed." << std::endl;

	}
	catch(...)
	{
		std::cout << "testing failed!! An exception was thrown"
				" in main."<< std::endl;
	}

	std::cout << "Testing Complete." << std::endl;

	return 0;
}
