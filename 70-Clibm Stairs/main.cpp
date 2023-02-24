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
    int dp[60] = {-1};
    int reClimb(int target, int count)
    {
        cout << count << endl;
        int total_sum = 0;
        if (count > target)
        {
            return 0;
        }

        // 探索済みチェック
        if (dp[count] == -1)
        {
            dp[count] = 0;
        }
        if (count + 1 == target)
        {
            total_sum++;
        }
        if (count + 2 == target)
        {
            total_sum++;
        }

        if (dp[count + 1] == -1)
        {
            reClimb(target, count + 1);
        }
        if (dp[count + 2] == -1)
        {
            reClimb(target, count + 2);
        }

        // 遷移する先がすでに探索済みであれば
        if (dp[count + 1] != -1)
        {
            total_sum += dp[count + 1];
        }
        if (dp[count + 2] != -1)
        {
            total_sum += dp[count + 2];
        }

        dp[count] = total_sum;
        return dp[0];
    }
    int climbStairs(int n)
    {
        for (int i = 0; i < 60; i++)
        {
            dp[i] = -1;
        }
        return reClimb(n, 0);
    }
};