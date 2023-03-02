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
    bool isPalindrome(string s)
    {
        auto start_s = s.begin();
        auto end_s = s.end();
        while (start_s != s.end() && end_s != s.begin())
        {
            bool is_skiped = false;
            char start_c = tolower(*start_s);
            char end_c = tolower(*end_s);
            if (!(isalpha(start_c) || isdigit(start_c)))
            {
                ++start_s;
                is_skiped = true;
            }
            if (!(isalpha(end_c) || isdigit(end_c)))
            {
                --end_s;
                is_skiped = true;
            }
            if (is_skiped)
            {
                continue;
            }
            if (start_c != end_c)
            {
                return false;
            }
            ++start_s;
            --end_s;
        }
        return true;
    }
};

int main()
{
    string s;
    Solution solution;
    cin >> s;
    solution.isPalindrome(s);
}