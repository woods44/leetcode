/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
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
    bool expands(int left, int right, int mid, int dl, int dr, string s, string t)
    {
        while (left >= 0 || right < t.length())
        {
            char lc = ' ';
            if (left >= 0)
            {
                lc = t[left];
            }
            char rc = ' ';
            if (right < t.length())
            {
                rc = t[right];
            }
            if (mid - dl == -1 && mid + dr == s.length())
            {
                return true;
            }
            if (mid - dl >= 0 && lc == s[mid - dl])
            {
                dl++;
            }
            if (mid + dr < t.length() && rc == s[mid + dr])
            {
                dr++;
            }
            right++;
            left--;
        }
        if (mid - dl == -1 && mid + dr == s.length())
        {
            return true;
        }
        return false;
    }
    bool isSubsequence(string s, string t)
    {
        if (s.length() == 0)
        {
            return true;
        }
        int mid = s.length() / 2;
        for (int x = 0; x < t.length(); ++x)
        {
            if (t[x] == s[mid])
            {
                if (s.length() % 2 != 0)
                {
                    if (expands(x, x, mid, 0, 0, s, t))
                    {
                        return true;
                    }
                }
                if (s.length() % 2 == 0)
                {
                    if (expands(x - 1, x, mid, 1, 0, s, t))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
int main()
{
    Solution s;
    cout << s.isSubsequence("adc", "ahbgdc") << endl;
}