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
    int reBob(int s, int l, vector<int> &nums)
    {
        int point = 0;
        int prePoint = 0;
        for (int i = s; i < l; ++i)
        {
            cout << "Pre i:" << i << " prePoint:" << prePoint << " point:" << point << endl;
            int temp = max(prePoint + nums[i], point);
            prePoint = point;
            point = temp;
            cout << "After i:" << i << " prePoint:" << prePoint << " point:" << point << endl;
        }
        return point;
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums[0];
        }
        int A = reBob(0, nums.size() - 1, nums);
        cout << "ResultA:" << A << endl;
        int B = reBob(1, nums.size(), nums);
        cout << "ResultB:" << B << endl;
        return max(A, B);
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 3, 4, 6, 7};
    cout << s.rob(nums) << endl;
}