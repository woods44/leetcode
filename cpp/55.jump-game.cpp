/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
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
    bool canJump(vector<int> &nums)
    {

        int preJamp = 0;
        vector<int> path;
        if (nums.size() < 2)
        {
            return true;
        }
        path.emplace_back(0);
        for (;;)
        {
            if (path.empty())
            {
                return false;
            }
            int i = path.back();
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
            i += nums[i];
            path.emplace_back(i);
        }
        return true;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> nums({3, 2, 1, 0, 0, 4});
    cout << s.canJump(nums) << endl;
}
