/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
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
    set<vector<int>> result;
    void back_track(vector<int> nums, int i, int n)
    {
        if (i == n - 1)
        {
            result.insert(nums);
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
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        back_track(nums, 0, nums.size());
        return vector<vector<int>>({result.begin(), result.end()});
    }
};
// @lc code=end
int main()
{
    vector<int> nums({1, 2, 3});
    Solution s;
    auto ans = s.permuteUnique(nums);
    for (auto r : ans)
    {
        cout << "[";
        for (auto i : r)
        {
            cout << i << ", ";
        }
        cout << "]" << endl;
    }
}