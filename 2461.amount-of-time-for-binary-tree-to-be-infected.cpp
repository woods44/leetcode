/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
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
    long long max = 0;
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.begin() + k - 1;
        while (right != nums.end())
        {
            set<int> s(left, right + 1);
            if (s.size() != k)
            {
                ++left;
                ++right;
                continue;
            }
            long long sum = accumulate(s.begin(), s.end(), 0LL);
            if (sum > max)
            {
                max = sum;
            }
            ++left;
            ++right;
        }
        return max;
    }
};
// @lc code=end
