/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
// @lc code=start
void swap(int *a, int *b)
{
    int tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}

/* クイックソートを行う関数 */
void quickSort(vector<int> &a, int left, int right)
{
    int pivot;
    int i, j;

    if (left >= right)
    {
        return;
    }
    pivot = a[left];

    i = left;
    j = right;
    while (1)
    {
        /* pivot以上の数字を左側から探索 */
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(&(a[i]), &(a[j]));

        i++;
        j--;
    }
    quickSort(a, left, i - 1);
    quickSort(a, j + 1, right);
}
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
int main()
{
    vector<int> nums({0, 1, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1});
    Solution s;
    s.sortColors(nums);
    for (auto n : nums)
    {
        cout << n << ", ";
    }
    cout << endl;
}