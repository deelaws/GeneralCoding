#include "stdafx.h"

int FindFirstOccurenceOfk(const std::vector<int> input, int k)
{
	int retval = -1;
	int left = 0, right = input.size() -1;
	int mid = 0;
	// the array is sorted so lets use binary search.

	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		//mid = left + (right  / 2);

		if (input[mid] == k)
		{
			retval = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return retval;
}

int SearchEntryEqualToIndex(const std::vector<int> input)
{
	int retval = -1;
	int left = 0, right = input.size() - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = left + ((right - left) / 2);

		if (input[mid] == mid)
		{
			retval = mid;
			break;
		}
		else if (input[mid] > mid)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return retval;
}

std::pair<int, int> FindSumSubArray(const std::vector<int> &A,
	const int k)
{
	int curr_sum = 0;
	int start_index = 0;

	for (size_t i = 0; i < A.size(); i++)
	{
		curr_sum += A[i];

		while (curr_sum > k)
		{
			curr_sum -= A[start_index++];
		}

		if (k == curr_sum)
		{
			return { start_index, (int)i };
		}
	}

	return{ -1,-1 };
}

std::pair<int, int> FindSumSubArrayWithNegative(const std::vector<int> &A,
	const int k)
{
	int curr_sum = 0;
	std::unordered_map<int, int> map;

	for (size_t i = 0; i < A.size(); i++)
	{
		curr_sum += A[i];

		// Found sum from index 0 to i.
		if (k == curr_sum)
		{
			return{ 0, i };
		}

		if (map.find(curr_sum - k) != map.end())
		{
			// found an index such that the sum  at that index my now = k
			return{ map[curr_sum - k] + 1, i };
		}

		map[curr_sum] = i;
	}

	return{ -1,-1 };
}