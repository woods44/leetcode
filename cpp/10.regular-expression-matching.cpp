/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
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
    bool result = false;
    void reMatch(int i, int r, string s, string p, vector<char> pattern)
    {
        char preC;
        if (i >= s.length())
        {
            return;
        }
        if (r == p.length())
        {
            result = true;
        }
        if (pattern.size() > 0)
        {
            preC = *(pattern.end() - 1); // 直前の一文字
        }
        char target = p[r];
        if (target == '*')
        {
            pattern.emplace_back(preC);
            reMatch(i + 1, r + 1, s, p, pattern);
        }
    }
    bool isMatch(string s, string p)
    {
        vector<char> pattern;
        pattern.emplace_back(s[0]);
        reMatch(1, 0, s, p, pattern);
        return result;
    }
};
// @lc code=end
int main()
{
    Solution s;
    cout << s.isMatch("aacvb", "cv") << endl;
}