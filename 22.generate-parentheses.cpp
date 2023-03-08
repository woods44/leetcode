/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
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
    vector<string> result;
    void backtrack(int r, int rc, string pattern)
    {
        pattern.push_back('(');
        backtrack(r, rc, pattern);
        
    }
    vector<string> generateParenthesis(int n)
    {
    }
};
// @lc code=end
