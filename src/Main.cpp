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

		TestEmpty();
		std::cout << "TestEmpty passed." << std::endl;

		TestGetCursorVal();
		std::cout << "TestCursorVal passed." << std::endl;

		TestSetCurserVal();
		std::cout << "TestSetCurserVal passed." << std::endl;

		TestCursorToFront();
		std::cout << "TestCursorToFront passed." << std::endl;

		TestCursorToBack();
		std::cout << "TestCursorToBack passed." << std::endl;

		TestClearList();
		std::cout << "TestClearList passed." << std::endl;

		TestPrePlusPlus();
		std::cout << "TestPrePlusPlus passed." << std::endl;

		TestPreMinusMinus();
		std::cout << "TestPreMinusMinus passed." << std::endl;
	}
	catch(...)
	{
		std::cout << "testing failed!! An exception was thrown"
				" in main."<< std::endl;
		return 0;
	}

	std::cout << std::endl << "Testing Complete." << std::endl;

	return 0;
}
