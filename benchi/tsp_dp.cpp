#include <random>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <time.h>
#include <set>
using namespace std;
const int INF = 1000100100;

int graph[20][20];
int dp[500000][20];
int V;
int E;
int rec(int c, int g)
{
    if (c == 0)
    {
        if (g == 0)
        {
            return 0;
        }
        return INF;
    }
    if (c & (1 << g) == 0)
    {
        return INF;
    }
    int &ret = dp[c][g];
    if (ret != 0)
    {
        return ret;
    }
    ret = INF;
    for (int u = 0; u < V; ++u)
    {
        // 探索済みだと探索を実施しないためXOR
        ret = min(ret, rec(c ^ (1 << u), u) + graph[u][g]);
    }
    return ret;
}

int main()
{
    int v, e;
    cin >> v >> e;
    V = v;
    E = e;
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            graph[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    int ans = rec((1 << v) - 1, 0);
    cout << ans << endl;
    return 0;
}