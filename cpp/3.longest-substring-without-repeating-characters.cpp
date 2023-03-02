/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
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
    int lengthOfLongestSubstring(string s)
    {
        if (s == "")
        {
            return 0;
        }
        int max = 1;
        int count = 1;
        auto left = s.begin();
        auto right = s.begin() + 1;
        set<char> box;
        box.insert(*left);
        while (right != s.end())
        {
            char c = *right;
            if (box.count(c) > 0)
            {
                box.clear();
                left = left + 1;
                right = left + 1;
                box.insert(*left);
                count = 1;
                continue;
            }
            box.insert(c);
            count++;
            right++;
            if (max < count)
            {
                max = count;
            }
        }
        return max;
    }
};
// @lc code=end
