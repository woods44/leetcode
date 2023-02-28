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
    long dp[101][101];
    int my = 0;
    int nx = 0;
    void dfs(int y, int x)
    {
        cout << y << " " << x << endl;
        if (y < 0 || x < 0 || y >= my || x >= nx)
        {
            return;
        }
        if (y == my - 1 && x == nx - 1)
        {
            return;
        }
        dp[y][x] = 0;
        if (dp[y + 1][x] == -1)
        {
            dfs(y + 1, x);
        }
        if (dp[y][x + 1] == -1)
        {
            dfs(y, x + 1);
        }
        if (y + 1 == my - 1 && x == nx - 1)
        {
            dp[y][x]++;
        }
        if (y == my - 1 && x + 1 == nx - 1)
        {
            dp[y][x]++;
        }
        if (dp[y][x + 1] != -1 && dp[y + 1][x] != -1)
        {
            dp[y][x] = dp[y][x + 1] + dp[y + 1][x];
        }
        return;
    }
    long uniquePaths(int m, int n)
    {
        if (m == 1 && n == 1)
        {
            return 1;
        }
        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                dp[y][x] = -1;
            }
        }
        my = m;
        nx = n;
        dfs(0, 0);
        return dp[0][0];
    }
};

int main()
{
    Solution solution;
    cout << solution.uniquePaths(10, 10) << endl;
}