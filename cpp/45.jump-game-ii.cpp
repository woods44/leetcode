/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
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
    int jump(vector<int> &nums)
    {
        int preJamp = 0;
        vector<int> path;
        if (nums.size() < 2)
        {
            return 0;
        }
        path.emplace_back(0);
        for (;;)
        {
            if (path.empty())
            {
                return false;
            }
            int i = path.back();
            cout << i << endl;
            if (i >= nums.size() - 1)
            {
                break;
            }
            if (i < 0)
            {
                return false;
            }

            if (nums[i] == 0)
            {
                path.pop_back();
                if (path.empty())
                {
                    return false;
                }
                nums[path.back()] -= 1;
                continue;
            }
            if ((nums[i] + i) >= nums.size() - 1)
            {
                return path.size();
            }
            auto max_index = max_element(nums.begin() + i + 1, nums.begin() + i + 1 + nums[i]);
            for (auto j = max_index; j <= (nums.begin() + i + nums[i]) && (*j == *max_index); ++j)
            {
                max_index = j;
            }
            i = distance(nums.begin(), max_index);
            path.emplace_back(i);
        }
        return path.size();
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> nums({10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0});
    cout << s.jump(nums) << endl;
}
