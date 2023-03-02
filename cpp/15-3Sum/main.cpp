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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int left = 0; left < nums.size(); left++)
        {
            int mid = left + 1;
            int right = nums.size() - 1;
            while (mid < right)
            {
                int sum = nums[left] + nums[right] + nums[mid];
                if (sum == 0)
                {
                    ans.insert({nums[left], nums[mid], nums[right]});
                    right--;
                    mid++;
                }
                else if (sum < 0)
                {
                    mid++;
                }
                else
                {
                    right--;
                }
            }
        }
        vector<vector<int>> output(ans.begin(), ans.end());
        return output;
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