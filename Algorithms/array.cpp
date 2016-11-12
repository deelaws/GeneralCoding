#include "stdafx.h"

#if defined(max)
    #undef max
#endif

#if defined(min)
    #undef min
#endif

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

static inline void swap(std::vector<int> & A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void ZigZag(std::vector<int> & A)
{
	bool greater = true;

	for (size_t i = 0; i < A.size() - 1; i++)
	{
		if (A[i] >= A[i + 1] && greater)
		{
			swap(A, i, i + 1);
		}
		else if (A[i] <= A[i + 1] && !greater)
		{
			swap(A, i, i + 1);
		}

		greater = !greater;
	}
}


int StocksMaxProfit(std::vector<int>& A)
{
    int max_profit = 0;
    int min_price = -1;

    for (auto i : A)
    {
        min_price = std::min(min_price, i);
        max_profit = std::max(i - min_price, max_profit);
    }

    return max_profit;
}

int SearchedSortedRotatedArray(std::vector<int>& A, int i)
{
    int ret = -1;
    int mid;
    int left = 0;
    int right = A.size() - 1;

    while (left < right)
    {
        mid = left + ((right - left) / 2);

        if (A[mid] == i)
        {
            return mid;
        }
        else if ((A[mid] < i) && (i < A[right]))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ret;
}

std::pair<int,int> FindSumOfPairClosest(std::vector<int>& A, int x)
{
    std::pair<int, int> ret = { -1,-1 };

    int diff = std::numeric_limits<int>::max();

    int right = A.size()-1;
    int left = 0;

    while (left < right)
    {
        auto new_diff = std::abs(x - (A[left] + A[right]));

        if (new_diff < diff)
        {
            // These two elements add up to be closer to x
            ret = { A[left], A[right] };
        }

        if (A[left] + A[right] > x)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return ret;
}
