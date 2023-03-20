/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
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
    void back_track(vector<int> nums, int i, int n)
    {
        if (i == n - 1)
        {
            result.emplace_back(nums);
            return;
        }
        for (int j = i; j < n; ++j)
        {
            swap(nums[i], nums[j]);
            back_track(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        back_track(nums, 0, nums.size());
        return result;
    }
};
// @lc code=end
