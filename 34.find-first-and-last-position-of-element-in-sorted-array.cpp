/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 2)
        {
            if (nums[0] == target && nums[1] == target)
            {
                return vector<int>({0, 1});
            }
            if (nums[0] == target)
            {
                return vector<int>({0, 0});
            }
            if (nums[1] == target)
            {
                return vector<int>({1, 1});
            }
            return vector<int>({-1, -1});
        }
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        while (left <= right)
        {
            int mid = (right + left) / 2;
            int num = nums[mid];
            if (mid == left || mid == right)
            {
                cout << mid << endl;
                if (nums[left] == target)
                {
                    ans = left;
                }
                if (nums[right] == target)
                {
                    ans = right;
                }
                break;
            }
            if (num > target)
            {
                right = mid;
                continue;
            }
            if (num < target)
            {
                left = mid;
                continue;
            }
            if (num == target)
            {
                ans = mid;
                break;
            }
        }
        if (ans == -1)
        {
            return vector<int>({-1, -1});
        }
        int min = ans;
        int max = ans;
        while (min > 0)
        {
            if (nums[min - 1] != target)
            {
                break;
            }
            --min;
        }
        while (max < nums.size() - 1)
        {
            if (nums[max + 1] != target)
            {
                break;
            }
            ++max;
        }
        return vector<int>({min, max});
    }
};
// @lc code=end
int main()
{
    vector<int> nums({1});
    Solution s;
    vector<int> r = s.searchRange(nums, 1);
    cout << r[0] << ", " << r[1] << endl;
}