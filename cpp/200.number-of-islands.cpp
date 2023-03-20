/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
// @lc code=start
struct UnionFind
{
    vector<int> par, rank, siz;

    // 構造体の初期化
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    // 根を求める
    int root(int x)
    {
        if (par[x] == -1)
        {
            return x;
        }
        else
        {
            return par[x] = root(par[x]);
        }
    }
    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }
    bool unite(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
        {
            return false;
        }
        if (rank[rx] < rank[ry])
        {
            swap(rx, ry);
        }
        par[ry] = rx;
        if (rank[rx] == rank[ry])
        {
            rank[rx]++;
        }
        siz[rx] += siz[ry];
        return true;
    }
    int size(int x)
    {
        return siz[root(x)];
    }
};

class Solution
{
public:
    int m = 0;
    int n = 0;
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int notIsLands = 0;
        int ans = 0;
        UnionFind uf(m * n);
        for (int h = 0; h < m; ++h)
        {
            for (int w = 0; w < n; ++w)
            {
                if (grid[h][w] == '1')
                {
                    dfs(grid, uf, w, h);
                }
                if (grid[h][w] == '0')
                {
                    ++notIsLands;
                }
            }
        }
        for (int i = 0; i < m * n; ++i)
        {
            if (i == uf.root(i))
            {
                ++ans;
            }
        }
        return ans - notIsLands;
    }
    void dfs(vector<vector<char>> &grid, UnionFind &uf, int x, int y)
    {
        int dx[4]{-1, 1, 0, 0};
        int dy[4]{0, 0, -1, 1};
        if (x >= n || x < 0 || y >= m || y < 0)
        {
            return;
        }
        grid[y][x] = '2';
        for (int i = 0; i < 4; ++i)
        {
            if (dx[i] + x < 0 || dx[i] + x >= n)
            {
                continue;
            }
            if (dy[i] + y < 0 || dy[i] + y >= m)
            {
                continue;
            }
            if (grid[dy[i] + y][dx[i] + x] == '1')
            {
                uf.unite((y * n) + x, ((dy[i] + y) * n) + dx[i] + x);
                dfs(grid, uf, dx[i] + x, dy[i] + y);
            }
        }
    }
};
// @lc code=end
