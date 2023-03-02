/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
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
    void re(int n, int i, int k, vector<int> pattern, vector<vector<int>> &result)
    {
        if (k == 0)
        {
            result.emplace_back(pattern);
            return;
        }
        for (int x = i + 1; x <= n; ++x)
        {
            pattern.emplace_back(x);
            re(n, x, k - 1, pattern, result);
            pattern.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> pattern;
        re(n, 0, k, pattern, result);
        return result;
    }
};
// @lc code=end
int main()
{
    Solution s;
    auto result = s.combine(20, 2);
    for (auto r : result)
    {
        for (auto c : r)
        {
            cout << c << ", ";
        }
        cout << endl;
    }
}