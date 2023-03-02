#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; ++i)
        {
            int counter = 0;
            for (int m = i; m != 0; m &= m - 1)
            {
                counter++;
            }
            ans.emplace_back(counter);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    for (int i : s.countBits(11))
    {
        cout << i << ", ";
    }
    cout << endl;
}