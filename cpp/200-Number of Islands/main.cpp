#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
    template <class T>
    void print2DVector(vector<vector<T>> target)
    {
        for (vector<T> t : target)
        {
            for (T s : t)
            {
                cout << s << ", ";
            }
            cout << endl;
        }
    }

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || x > grid[0].size() - 1)
        {
            return;
        }
        if (y < 0 || y > grid.size() - 1)
        {
            return;
        }
        if (grid[y][x] == '2')
        {
            return;
        }
        if (grid[y][x] == '1')
        {
            grid[y][x] = '2';
        }
        if (grid[y][x] == '0')
        {
            return;
        }
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[y].size(); ++x)
            {
                if (grid[y][x] == '1')
                {
                    dfs(grid, x, y);
                    ++count;
                }
            }
        }
        print2DVector(grid);
        return count;
    }
};

int main()
{
    vector<vector<char>> matrix{{'0', '0', '0'}, {'1', '0', '0'}, {'0', '0', '1'}};
    Solution solution;
    bool ans = solution.numIslands(matrix);
    cout << ans << endl;
}