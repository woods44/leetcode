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
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        auto i = 0;
        while (i < nums.size() - 1)
        {
            int target = nums[i];
            if (nums[i + 1] != target)
            {
                return target;
            }
            while (nums[i] == target)
            {
                i++;
            }
        }
        return nums[i];
    }
    int bitSingleNumber(vector<int> &nums)
    {
        int x = 0;
        for (auto num : nums)
        {
            x ^= num;
            cout << x << endl;
        }
        return x;
    }
};

int main()
{
    vector<int> nums{7, 3, 7, 4, 4};
    Solution s;
    cout << s.bitSingleNumber(nums) << endl;
}