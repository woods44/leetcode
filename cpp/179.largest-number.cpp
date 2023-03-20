/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
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
    int t = *a;
    *a = *b;
    *b = t;
}

bool isMinNum(int a, int b)
{
    string as = to_string(a);
    string bs = to_string(b);
    int head_a = int(as[0] - '0');
    int head_b = int(bs[0] - '0');
    if (head_a < head_b)
    {
        return true;
    }
    if (head_a == head_b)
    {
        return a < b;
    }
    return false;
}

int partition(int array[], int l, int r)
{
    int pivot = array[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        if (isMinNum(array[i], pivot))
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[r]);
    return (i + 1);
}

void quickSort(int array[], int l, int r)
{
    if (l < r)
    {
        int pivot = partition(array, l, r);
        quickSort(array, l, pivot - 1);
        quickSort(array, pivot + 1, r);
    }
}

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int array[nums.size()];
        copy(nums.begin(), nums.end(), array);
        quickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);
        for (auto a : array)
        {
            cout << a << endl;
        }
        return "0";
    }
};
// @lc code=end
int main()
{
    vector<int> nums({3, 30, 34, 5, 9});
    Solution s;
    s.largestNumber(nums);
}
