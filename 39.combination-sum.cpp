/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
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
    vector<vector<int>> result;
    void reComb(int i, int r, vector<int> &candidates, int target, vector<int> pattern)
    {
        int sum = accumulate(pattern.begin(), pattern.end(), 0);
        // for (auto r : pattern)
        // {
        //     cout << r << ", ";
        // }
        // cout << endl;
        // cout << "i" << i << "sum:" << sum << endl;
        if (sum == target)
        {
            result.emplace_back(pattern);
            return;
        }
        if (i >= candidates.size())
        {
            return;
        }
        if (sum > target)
        {
            return;
        }
        pattern.emplace_back(candidates[i]);
        reComb(i, r + 1, candidates, target, pattern);
        pattern.pop_back();
        reComb(i + 1, r, candidates, target, pattern);
        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> pattern;
        reComb(0, 0, candidates, target, pattern);
        return result;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> candidates({2, 3, 5});
    vector<vector<int>> result = s.combinationSum(candidates, 8);
    for (auto r : result)
    {
        for (auto c : r)
        {
            cout << c << ", ";
        }
        cout << endl;
    }
}
