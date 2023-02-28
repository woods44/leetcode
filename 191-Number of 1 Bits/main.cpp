#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (; n != 0; n &= n - 1)
        {
            count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(11) << endl;
}