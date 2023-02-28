#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <bitset>
using namespace std;
class Solution
{
public:
    int solve(string s)
    {
        int ud = 0;
        int rl = 0;
        set<pair<int, int>> visited({pair<int, int>(0, 0)});
        for (char c : s)
        {
            if (c == 'U')
            {
                ud++;
            }
            if (c == 'D')
            {
                ud--;
            }
            if (c == 'R')
            {
                rl++;
            }
            if (c == 'L')
            {
                rl--;
            }
            if (visited.count(pair<int, int>(ud, rl)) > 0)
            {
                return 1;
            }
            visited.insert(pair<int, int>(ud, rl));
        }
        return 0;
    }
};

int main()
{
    Solution s;
    string n;
    cin >> n;
    int ans = s.solve(n);
    cout << ans << endl;
}