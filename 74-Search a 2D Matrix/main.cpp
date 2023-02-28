#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;
        while (left + 1 < right)
        {
            int mid = (int)((left + right) / 2);
            if (matrix[mid][0] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        if ((matrix[left][0] == target || matrix[right][0] == target))
        {
            return true;
        }
        int row = 0;
        if (matrix[right][0] > target)
        {
            row = left;
        }
        if (matrix[right][0] < target)
        {
            row = right;
        }
        left = 0;
        right = matrix[row].size() - 1;
        while (left + 1 < right)
        {
            int mid = (int)((left + right) / 2);
            if (matrix[row][mid] < target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return (matrix[row][left] == target || matrix[row][right] == target);
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    // vector<vector<int>> matrix{{1}};
    int target = 11;
    Solution solution;
    bool ans = solution.searchMatrix(matrix, target);
    cout << ans << endl;
}