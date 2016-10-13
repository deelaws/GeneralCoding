#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace DataStructs;


extern void FooFunction();

namespace TestProject
{
	TEST_CLASS(AlgorithmUnitTest)
	{
	public:

		TEST_METHOD(FirstOccurenceOfK_Test)
		{
			std::vector<int> vec;
			vec.emplace_back(-10);
			vec.emplace_back(-3);
			vec.emplace_back(2);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(5);
			vec.emplace_back(10);
			vec.emplace_back(14);

			int first_occurence = FindFirstOccurenceOfk(vec, 5);

			Assert::AreEqual(true, first_occurence == 3);
		}

		TEST_METHOD(SearchEntryEqualToIndex_Test)
		{
			std::vector<int> vec;
			vec.emplace_back(-2);
			vec.emplace_back(0);
			vec.emplace_back(2);
			vec.emplace_back(3);
			vec.emplace_back(7);
			vec.emplace_back(9);

			int first_occurence = SearchEntryEqualToIndex(vec);

			Assert::AreEqual(true, first_occurence == 2 || first_occurence == 3);
		}
	};
}