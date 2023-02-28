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
    int count = 0;
    int sizeN = 0;
    void dfs(int pos, int pVal, int *a, int *b)
    {
        if (pos >= sizeN - 1)
        {
            cout << "couter:" << count << endl;
            count++;
            return;
        }
        if (a[pos + 1] != pVal)
        {
            dfs(pos + 1, a[pos], a, b);
        }
        if (b[pos + 1] != pVal)
        {
            dfs(pos + 1, b[pos], a, b);
        }
        return;
    }
    int solve(int *a, int *b, int n)
    {
        sizeN = n;
        dfs(0, a[0], a, b);
        return count;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }
    int ans = s.solve(a, b, n);
    cout << ans << endl;
}