/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
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
    int searchMax(vector<int> nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int mid = nums.size() / 2;
        int left = searchMax(vector<int>{nums.begin(), nums.begin() + mid});
        int right = searchMax(vector<int>{nums.begin() + mid, nums.end()});
        return max(left, right);
    }
    int maxSubArray(vector<int> &nums)
    {
        int m = searchMax(nums);
        return m;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> nums({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    cout << s.maxSubArray(nums) << endl;
}