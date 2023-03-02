/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
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
    string extends(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s)
    {
        int max = 0;
        string maxString = "";
        for (int i = 0; i < s.length(); ++i)
        {
            string result = extends(s, i, i);
            // cout << "奇数長" << i << ": " << result << endl;
            if (max < result.length())
            {
                max = result.length();
                maxString = result;
            }
            result = extends(s, i, i + 1);
            // cout << "偶数長" << i << ": " << result << endl;
            if (max < result.length())
            {
                max = result.length();
                maxString = result;
            }
        }
        return maxString;
    }
};
// @lc code=end
int main()
{
    Solution s;
    string in = "abcdaaabaaa";
    cout << "input: " << in << endl;
    string answer = s.longestPalindrome(in);
    cout << "A: " << answer << endl;
}