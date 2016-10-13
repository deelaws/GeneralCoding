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