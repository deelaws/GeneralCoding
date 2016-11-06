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
