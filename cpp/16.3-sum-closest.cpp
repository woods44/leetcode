/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
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
    int threeSumClosest(vector<int> &nums, int target)
    {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int near = INT_MAX;
        int answer = -1;
        for (int left = 0; left < nums.size(); left++)
        {
            int mid = left + 1;
            int right = nums.size() - 1;
            while (mid < right)
            {
                int sum = nums[left] + nums[right] + nums[mid];
                if (abs(target - sum) < near)
                {
                    near = abs(target - sum);
                    answer = sum;
                    continue;
                }
                if (sum < target)
                {
                    mid++;
                }
                else
                {
                    right--;
                }
            }
        }
        return answer;
    }
};
// @lc code=end
