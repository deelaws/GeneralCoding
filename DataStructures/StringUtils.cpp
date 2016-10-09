#include "stdafx.h"


inline uint32_t Factorial(uint32_t input)
{
    uint32_t ret = input;

    for (int i = input -1; i > 0; i--)
    {
        ret *= i;
    }

    return ret;
}

std::vector<std::string> FindPermutation(const char *pStr)
{
    std::vector<std::string> perms;

    if (NULL != pStr)
    {
        // Calculate number of permuations of the input string.
        uint32_t num_perms = Factorial(strlen(pStr));
        perms.resize(num_perms);

        perms.push_back(std::string(&pStr[0]));

    }

    return perms;
}