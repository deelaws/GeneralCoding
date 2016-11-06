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