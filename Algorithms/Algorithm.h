#pragma once
#include <vector>

using namespace std;

/*
Find the first occurence of k in a sorted array.
*/
int FindFirstOccurenceOfk(const std::vector<int> input, int k);

/*
Design an efficient algorithm that takes a sorted array of distinct integers
and returns an index i such that the element at index i == i.
*/
int SearchEntryEqualToIndex(const std::vector<int> input);


/*
Generates all possible matching parenthesis
*/
vector<std::string> MatchingParenthesis(int k);

/*
Reverses a string
*/
void reverse_string(char *str);

/*
Reverses a string without affecting any special characters.
*/
void reverse_string_special(char *str);


/*
Find Subarray with a given sum k.

Input array doesnot contain negative numbers.
*/
std::pair<int, int> FindSumSubArray(const std::vector<int> &A,
	const int k);

/*
Find Subarray with a given sum k.

Input array can contain negative numbers.
*/
std::pair<int, int> FindSumSubArrayWithNegative(const std::vector<int> &A,
	const int k);

/*
Convert  the input array to zig zag format

a < b > c < d > e < f > g
*/
void ZigZag(std::vector<int> & A);

/*
You're allowed to buy and sell a stock once.
You have to buy before you sell.

Find the maximum profit to be made for a stock with a 
given prices over a bunch of days.
*/
int StocksMaxProfit(std::vector<int>& A);

/*
Search for an element in a sorted array which is
rotated.

1 2 3 4 5 might become 3 4 5 1 2

*/
int SearchedSortedRotatedArray(std::vector<int>& A, int i);

/*
Given a sorted array and a number x,
find a pair in array whose sum is closest to x.
*/
std::pair<int, int> FindSumOfPairClosest(std::vector<int>& A, int x);

/*
 TODO: Find triplets in array which add up to x.
*/

/*
Convert Binary Number in string format to decimal number.
AKA, Binary to Decimal.
*/
int BinaryToDecimal(const std::string &num);

/*
Add two binary numbers in string format.
Return the added binary number in string format.
*/
std::string AddBinaryNumbers(std::string a, std::string b);