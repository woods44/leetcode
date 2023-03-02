/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto idx1 = nums1.begin();
        auto idx2 = nums2.begin();
        vector<int> marge;
        while (true)
        {
            int i1 = INT_MAX;
            int i2 = INT_MAX;
            if (idx1 != nums1.end())
            {
                i1 = *idx1;
            }
            if (idx2 != nums2.end())
            {
                i2 = *idx2;
            }
            if (i1 == INT_MAX && i2 == INT_MAX)
            {
                break;
            }
            if (i1 < i2)
            {
                marge.emplace_back(i1);
                idx1++;
            }
            else
            {
                marge.emplace_back(i2);
                idx2++;
            }
        }
        int center = marge.size() / 2;
        if (marge.size() % 2 == 0)
        {
            return (double)(marge[center] + marge[center - 1]) / 2.000;
        }
        return marge[center];
    }
};
// @lc code=end
int main()
{
    vector<int> nums1({1, 3});
    vector<int> nums2({2, 4});
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    ;
}
