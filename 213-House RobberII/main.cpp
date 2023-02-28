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
    int dp[101];
    int n;
    void reBob(int p, vector<int> visited)
    {
        if (visited[p] == 1)
        {
            return;
        }
        if (p == 0)
        {
        }
        visited[p] = 1;
        
    }
    int rob(vector<int> &nums)
    {
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2};
    cout << s.rob(nums) << endl;
    cout << endl;
}