/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> tokens;
        for (char c : s)
        {
            if (c == '}')
            {
                if (tokens.empty() || tokens.top() != '{')
                {
                    return false;
                }
                tokens.pop();
                continue;
            }
            if (c == ']')
            {
                if (tokens.empty() || tokens.top() != '[')
                {
                    return false;
                }
                tokens.pop();
                continue;
            }
            if (c == ')')
            {
                if (tokens.empty() || tokens.top() != '(')
                {
                    return false;
                }
                tokens.pop();
                continue;
            }
            tokens.push(c);
        }
        if (tokens.empty())
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
