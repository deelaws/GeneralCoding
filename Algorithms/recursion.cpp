#pragma once
#include "stdafx.h"

static void MatchingParenthesis_helper(int left_to_add,
    int right_to_add,
    const std::string& valid_prefix,
    vector<std::string>& matched)
{
    if (!left_to_add && !right_to_add)
    {
        matched.emplace_back(valid_prefix);
        return;
    }

    if (left_to_add > 0)
    {
        MatchingParenthesis_helper(left_to_add - 1,
            right_to_add,
            valid_prefix + "(",
            matched);
    }

    if (left_to_add < right_to_add)
    {
        MatchingParenthesis_helper(left_to_add,
            right_to_add - 1,
            valid_prefix + ")",
            matched);
    }
}

vector<std::string> MatchingParenthesis(int k)
{
    vector<string> matched;

    MatchingParenthesis_helper(k, k, "", matched);

    return matched;
}