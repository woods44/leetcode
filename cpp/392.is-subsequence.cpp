/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
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
    string target;
    template <class T>
    bool combination(vector<T> &arr, int r)
    {
        if (arr.size() < r)
        {
            printf("combination ERROR: r is larger than arr.size()\n");
            return false;
            exit(1);
        }

        vector<T> pattern;
        vector<vector<T>> result;
        bool flag = false;
        dfs_combination(arr, 0, r, pattern, flag);
        return flag;
    }
    void dfs_combination(vector<char> &arr, int idx, int r, vector<char> &pattern, bool &result)
    {
        if (r == 0)
        {
            string ans(pattern.begin(), pattern.end());
            if (ans == target)
            {
                result = true;
            }
            return;
        }
        if ((idx + r) > arr.size())
        {
            return;
        }
        for (int i = idx; i < arr.size(); ++i)
        {
            if (arr[i] == target[target.size() - r])
            {
                pattern.push_back(arr[i]);
                dfs_combination(arr, i + 1, r - 1, pattern, result);
                if (result)
                {
                    return;
                }
                pattern.pop_back();
            }
            // dfs_combination(arr, i, r, pattern, result);
        }
        return;
    }
    bool isSubsequence(string s, string t)
    {
        vector<char> input({t.begin(), t.end()});
        target = s;
        bool result = combination(input, s.size());
        return result;
    }
};
// int main()
// {
//     Solution a;
//     cout << a.isSubsequence("abc", "ahbgdc") << endl;
// }
// @lc code=end
