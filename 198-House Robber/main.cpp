#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    int dp[100000] = {-1};
    int reRob(int curr, vector<int> &nums)
    {
        if (curr >= nums.size())
        {
            dp[curr] = 0;
            return 0;
        }
        if (dp[curr] == -1)
        {
            dp[curr] = 0;
        }
        if (curr + 2 >= nums.size() || curr + 3 >= nums.size())
        {
            dp[curr] = nums[curr];
        }
        if (dp[curr + 2] == -1)
        {
            reRob(curr + 2, nums);
        }
        if (dp[curr + 3] == -1)
        {
            reRob(curr + 3, nums);
        }
        if (dp[curr + 2] != -1 && dp[curr + 3] != -1)
        {
            dp[curr] = max(dp[curr + 2] + nums[curr], dp[curr + 3] + nums[curr]);
        }
        return dp[0];
    }
    int rob(vector<int> &nums)
    {
        for (int i = 0; i < 100000; i++)
        {
            dp[i] = -1;
        }
        int ans = reRob(0, nums);
        for (int i = 0; i < 7; ++i)
        {
            cout << dp[i] << " ";
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2};
    nums.insert(nums.begin(), 0);
    nums.insert(nums.begin(), 0);
    cout << s.rob(nums) << endl;
    cout << endl;
}