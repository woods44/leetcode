/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
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
    map<char, vector<char>> phone;
    vector<string> result;
    void comb(string digits, int i, int j, int r, string pattern)
    {
        if (r == 0)
        {
            result.emplace_back(pattern);
            return;
        }
        if (i >= digits.size())
        {
            return;
        }
        auto d = digits[i]; // 押した番号
        if (j >= phone[d].size())
        {
            return;
        }
        auto c = phone[d][j];
        pattern.push_back(c);
        comb(digits, i + 1, 0, r - 1, pattern); // 最初の文字を採用する場合
        pattern.pop_back();
        comb(digits, i, j + 1, r, pattern); // 最初の文字を採用しない
    }
    vector<string> letterCombinations(string digits)
    {
        string pattern;
        if (digits == "")
        {
            return result;
        }
        phone['2'] = {'a', 'b', 'c'};
        phone['3'] = {'d', 'e', 'f'};
        phone['4'] = {'g', 'h', 'i'};
        phone['5'] = {'j', 'k', 'l'};
        phone['6'] = {'m', 'n', 'o'};
        phone['7'] = {'p', 'q', 'r', 's'};
        phone['8'] = {'t', 'u', 'v'};
        phone['9'] = {'w', 'x', 'y', 'z'};
        comb(digits, 0, 0, digits.size(), pattern);
        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    string digits = "2";
    vector<string> result = s.letterCombinations(digits);
    for (auto r : result)
    {
        cout << r << endl;
    }
}
