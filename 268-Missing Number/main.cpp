#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        bitset<10001> m;
        int max = 0;
        for (int n : nums)
        {
            if (n > max)
            {
                max = n;
            }
            m.set(n); // 右からnbit目のフラグを立てる
        }
        m = ~m;
        for (int i = 0; i < 10000; ++i)
        {
            if (m.test(i))
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums({1, 2, 3, 10000, 0});
    cout << s.missingNumber(nums) << endl;
}