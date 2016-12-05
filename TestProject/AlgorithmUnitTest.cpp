#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace DataStructs;

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

        TEST_METHOD(MatchingParenthesis_Two)
        {
            std::vector<string> matched = MatchingParenthesis(2);

            Assert::AreEqual(matched.size(), (size_t) 2);
            Logger::WriteMessage("Running test: MatchingParenthesis_Two");
            for (string s : matched)
            {
                Logger::WriteMessage(s.c_str());
                OutputDebugStringA("\n");
            }
            std::cerr << "Text" << std::endl;
        }

		TEST_METHOD(ReverseString_Simple)
		{
			char str[] = "a*b&cde*^%fgh&*ij)k^l^m";
			Logger::WriteMessage(str);
			reverse_string_special(str);
			
			Logger::WriteMessage("String reversed to:\n");
			Logger::WriteMessage(str);

			Assert::AreEqual("m*l&kji*^%hgf&*ed)c^b^a", str);
		}

		TEST_METHOD(SumSubArray_multiple_tests)
		{
			std::vector<int> a = { 15, 2, 4, 8, 9, 5, 10, 23 };

			auto ret = FindSumSubArray(a, 23);

			Assert::AreEqual(1, ret.first);
			Assert::AreEqual(4, ret.second);

			a = { 1, 4, 20, 3, 10, 5 };
			ret = FindSumSubArray(a, 33);

			Assert::AreEqual(2, ret.first);
			Assert::AreEqual(4, ret.second);

			a = { 1, 4, 0, 0, 3, 10, 5 };
			ret = FindSumSubArray(a, 7);

			Assert::AreEqual(1, ret.first);
			Assert::AreEqual(4, ret.second);
		}

		TEST_METHOD(SumSubArray_with_negative_ints)
		{
			std::vector<int> a = { 1,2,5,-1,6,7,9 };

			auto ret = FindSumSubArrayWithNegative(a, 4);

			Assert::AreEqual(2, ret.first);
			Assert::AreEqual(3, ret.second);
		}

        TEST_METHOD(SortedRoatedArray_simple)
        {
            std::vector<int> a = { 7,8,9,10,1,2,3,4,5,6};

            auto ret = SearchedSortedRotatedArray(a, 8);

            Assert::AreEqual(1, ret);
        }

        TEST_METHOD(SortedRoatedArray_fully_sorted_array)
        {
            // keep the array fully sorted
            std::vector<int> a = { 1,2,3,4,5,6,7,8,9,10 };

            auto ret = SearchedSortedRotatedArray(a, 8);

            Assert::AreEqual(7, ret);
        }

		TEST_METHOD(AddBinaryNumbers_UT)
		{
			std::string num_one = "000";
			std::string num_two = "111";

			auto ret = AddBinaryNumbers(num_one, num_two);

			Assert::AreEqual(ret.compare("111") == 0, true);

			// 1 + 1
			num_one = "1";
			num_two = "1";

			ret = AddBinaryNumbers(num_one, num_two);

			Assert::AreEqual(ret.compare("10") == 0, true);

			// 3 + 3 = 6
			num_one = "11";
			num_two = "11";

			ret = AddBinaryNumbers(num_one, num_two);

			Assert::AreEqual(ret.compare("110") == 0, true);
		}

		TEST_METHOD(BinaryToDecimal_UT)
		{
			std::string binary_num = "1000";
			auto ret = BinaryToDecimal(binary_num);
			Assert::AreEqual(ret, 8);

			binary_num = "110";
			ret = BinaryToDecimal(binary_num);
			Assert::AreEqual(ret, 6);

			binary_num = "101";
		    ret = BinaryToDecimal(binary_num);
			Assert::AreEqual(ret, 5);
		
			binary_num = "1";
			ret = BinaryToDecimal(binary_num);
			Assert::AreEqual(ret, 1);

			binary_num = "0";
			ret = BinaryToDecimal(binary_num);
			Assert::AreEqual(ret, 0);
		}
	};
}