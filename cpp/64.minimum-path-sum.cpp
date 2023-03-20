/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
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
    using P = pair<long, int>;
    int dp[200][200];
    void dfs(int x, int y, vector<vector<int>> grid)
    {
        if (x > grid[0].size() - 1)
        {
            return;
        }
        if (y > grid.size() - 1)
        {
            return;
        }
        if (x == grid[0].size() - 1 && y == grid.size() - 1)
        {
            return;
        }
        if (y + 1 < grid.size())
        {
            dp[y + 1][x] = min(dp[y + 1][x], dp[y][x] + grid[y + 1][x]);
            dfs(x, y + 1, grid);
        }
        if (x + 1 < grid[0].size())
        {
            dp[y][x + 1] = min(dp[y][x + 1], dp[y][x] + grid[y][x + 1]);
            dfs(x + 1, y, grid);
        }
        return;
    }
    void dijkstra(const vector<vector<int>> &grid, int s, vector<long long> &dis)
    {
        int N = grid.size() * grid[0].size();
        dis.resize(N, 1LL << 60);
        priority_queue<P, vector<P>, greater<P>> pq; // 「仮の最短距離, 頂点」が小さい順に並ぶ
        dis[s] = 0;
        pq.emplace(dis[s], s);
        while (!pq.empty())
        {
            P p = pq.top();
            pq.pop();
            int v = p.second;
            if (dis[v] < p.first)
            { // 最短距離で無ければ無視
                continue;
            }
            for (auto &e : G[v])
            {
                if (dis[e.to] > dis[v] + e.cost)
                { // 最短距離候補なら priority_queue に追加
                    dis[e.to] = dis[v] + e.cost;
                    pq.emplace(dis[e.to], e.to);
                }
            }
        }
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[0].size(); ++x)
            {
                dp[y][x] = INT_MAX;
            }
        }
        dp[0][0] = grid[0][0];
        dfs(0, 0, grid);
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end
