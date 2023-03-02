#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
template <class T>
void vectorPrint(vector<T> &vec)
{
    for (auto &a : vec)
    {
        cout << a;
        if (&a != &vec.back())
        {
            cout << " ";
        }
    }
    cout << endl;
}
class Solution
{
public:
    set<vector<int>> ans;
    void dfs(int curr, vector<int> candidates, int target, vector<int> buf)
    {
        int cSum = accumulate(buf.begin(), buf.end(), 0);
        if (cSum == target)
        {
            sort(buf.begin(), buf.begin() + curr);
            vector<int> it(buf.begin(), buf.begin() + curr);
            ans.insert(it);
            return;
        }
        if (cSum > target)
        {
            return;
        }
        for (int j = 0; j < candidates.size(); ++j)
        {
            buf[curr] = candidates[j];
            dfs(curr + 1, candidates, target, buf);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> buf;
        buf.resize(30);
        dfs(0, candidates, target, buf);
        vector<vector<int>> v_ans(ans.begin(), ans.end());
        return v_ans;
    }
};

int main()
{
    {
        vector<int> candidate{36, 21, 2, 3, 23, 24, 38, 22, 11, 14, 15, 25, 32, 19, 35, 26, 31, 13, 34, 29, 12, 37, 17, 20, 39, 30, 40, 28, 27, 33};
        // vector<int> candidate{3, 5, 7};
        cout << candidate.size() << endl;
        Solution s;
        int target = 35;
        auto ans = s.combinationSum(candidate, target);
    }
}