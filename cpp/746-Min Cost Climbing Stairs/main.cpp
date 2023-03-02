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
    int dp[1020] = {-1};

    int reCost(int target, int curr, vector<int> &cost)
    {
        int costTotal = 0;
        if (curr >= target)
        {
            return 0;
        }
        if (dp[curr] == -1)
        {
            dp[curr] = INT_MAX;
        }
        if (curr + 1 >= target || curr + 2 >= target)
        {
            costTotal = cost[curr];
            dp[curr] = cost[curr];
        }

        if (dp[curr + 1] == -1)
        {
            reCost(target, curr + 1, cost);
        }
        if (dp[curr + 2] == -1)
        {
            reCost(target, curr + 2, cost);
        }

        if (dp[curr + 1] != -1 && dp[curr + 2] != -1)
        {
            dp[curr] = min(dp[curr + 1] + cost[curr], dp[curr + 2] + cost[curr]);
        }
        return dp[0];
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 0; i < 1020; i++)
        {
            dp[i] = -1;
        }
        // 開始位置を示すダミー
        int target = cost.size() + 1;
        cost.insert(cost.begin(), 0);
        return reCost(target, 0, cost);
    }
};