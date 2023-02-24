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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        auto left = nums.begin();
        auto right = nums.end() - 1;
        auto mid = left + 1;
        while (right > (nums.begin() + 1))
        {
            int a = *mid;
            int b = *left;
            int c = *right;
            if ((a + b + c) == 0)
            {
                if (c < b)
                {
                    swap(c, b);
                }
                if (b < a)
                {
                    swap(b, a);
                }
                if (c < b)
                {
                    swap(c, b);
                }
                vector<int> res{a, b, c};
                ans.insert(res);
            }
            if (mid == (right - 1))
            {
                if (left >= (right - 2))
                {
                    right--;
                    left = nums.begin();
                    mid = left + 1;
                    continue;
                }
                else
                {
                    left++;
                    mid = left + 1;
                    continue;
                }
            }
            mid++;
        }
        vector<vector<int>> r(ans.begin(), ans.end());
        return r;
    }
};

int main()
{
    {
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        Solution s;
        auto a = s.threeSum(nums);
        for (vector<int> aa : a)
        {
            vectorPrint(aa);
        }
    }
}