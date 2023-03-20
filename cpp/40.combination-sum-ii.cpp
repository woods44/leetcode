/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
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
    set<vector<int>> result;
    map<int, int> counter;
    int totalSum;
    void reComb(int i, int r, vector<int> &candidates, int target, vector<int> pattern, int sum)
    {
        if (sum == target)
        {
            result.insert(pattern);
            return;
        }
        if (i >= candidates.size())
        {
            return;
        }
        if (sum > target)
        {
            return;
        }
        pattern.emplace_back(candidates[i]);
        sum += candidates[i];
        reComb(i + 1, r + 1, candidates, target, pattern, sum);
        pattern.pop_back();
        sum -= candidates[i];
        reComb(i + 1, r, candidates, target, pattern, sum);
        return;
    }
    void mapComb(map<int, int>::iterator itr, vector<int> candidates, int target, map<int, int> pattern, int sum)
    {
        if (itr->second < pattern[itr->first])
        {
            return;
        }
        if (sum == target)
        {
            vector<int> ans;
            for (auto m : pattern)
            {
                for (int j = 0; j < m.second; ++j)
                {
                    ans.emplace_back(m.first);
                }
            }
            result.insert(ans);
            return;
        }

        if (itr == counter.end())
        {
            return;
        }
        if (sum > target)
        {
            return;
        }
        pattern[itr->first]++;
        sum += itr->first;
        mapComb(itr, candidates, target, pattern, sum);
        pattern[itr->first]--;
        sum -= itr->first;
        mapComb(++itr, candidates, target, pattern, sum);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        map<int, int> pattern;
        sort(candidates.begin(), candidates.end());
        for (auto c : candidates)
        {
            counter[c]++;
        }
        mapComb(counter.begin(), candidates, target, pattern, 0);
        // reComb(0, 0, candidates, target, pattern, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> candidates({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    vector<vector<int>> result = s.combinationSum2(candidates, 30);
    for (auto r : result)
    {
        for (auto c : r)
        {
            cout << c << ", ";
        }
        cout << endl;
    }
}