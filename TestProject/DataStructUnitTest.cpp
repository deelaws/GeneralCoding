#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace DataStructs;


extern void FooFunction();

namespace TestProject
{		
	TEST_CLASS(DataStructUnitTest)
	{
	public:

        TEST_METHOD(BinaryTreeInsert)
        {
            BinaryTree bt(4);
        }
		
		TEST_METHOD(LinkedListSingleItem)
		{

            FooFunction();
            waleed wa;
            wa.PleaseWork();
            /*
            // Create a new linkedlist
            LinkedList<int> myList;



            for (int i = 0; i < 10; i++)
            {
                myList.Insert(i);
            }*/

            // Last item that was added in the linked list should be 9
		}

	};
}