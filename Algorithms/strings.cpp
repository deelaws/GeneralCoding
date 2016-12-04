#include "stdafx.h"

void reverse_string(char *str)
{
	char *end = str + strlen(str) - 1;

	while (str < end)
	{
		*str ^= *end;
		*end ^= *str;
		*str ^= *end;

		str++;
		end--;
	}
}


inline bool is_alphabet(char *c)
{
	_ASSERT(NULL != c);

	if ((('a' <= *c) && (*c <= 'z')) || (('A' <= *c) && (*c <= 'Z')))
	{
		return true;
	}

	return false;
}

void reverse_string_special(char *str)
{
	char *end = str + strlen(str) - 1;

	while (str < end)
	{
		if (! is_alphabet(str))
		{
			str++;
			continue;
		}

		if (!is_alphabet(end))
		{
			end--;
			continue;
		}

		// They both are within range. So  reverse the two
		*str ^= *end;
		*end ^= *str;
		*str ^= *end;

		str++;
		end--;
	}
}
#include <string> 

std::string AddBinaryNumbers(std::string a, std::string b)
{
	std::string added;

	int len_a = a.length()-1;
	int len_b = b.length()-1;
	int sum = 0;

	while (len_a >= 0 || len_b >= 0 || sum > 0)
	{
		if (len_a >= 0)
		{
			sum += (a[len_a--] - '0');
		}
		if (len_b >= 0)
		{
			sum += (b[len_b--] - '0');
		}
		
		added.push_back('0' + (sum %2));

		sum = sum <= 1 ? 0 : 1;
	}

	// Reverse string before returning.
	std::reverse(added.begin(), added.end());

	return added;
}