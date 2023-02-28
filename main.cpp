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
    int adder(int a, int b, bool subA, bool subB)
    {
        int sum = 0;
        int pC = subA || subB;
        int keta = max(log2(a), log2(b)) + 0.9999;
        for (int i = 0; i < keta; ++i)
        {
            int bitA = (a & (1 << i)) >> i;
            int bitB = (b & (1 << i)) >> i;
            bitA = bitA ^ subA;
            bitB = bitB ^ subB;
            cout << bitA << " " << bitB << endl;
            int c = bitA & bitB;
            int s = bitA ^ bitB;
            int secC = s & pC;
            s = s ^ pC;
            if (s == 1)
            {
                sum |= (1 << i);
            }
            cout << i << ": " << bitset<32>(sum) << endl;
            pC = c;
        }
        if (pC == 1)
        {
            sum |= (1 << keta);
        }
        if (subA || subB)
        {
            sum |= (1 << 31);
        }
        return sum;
    }
    int getSum(int a, int b)
    {
        int sum = 0;
        bool subA = false;
        bool subB = false;
        bitset<32> bitsetA(a);
        bitset<32> bitsetB(b);
        if (bitsetA.test(31))
        {
            a = ~a + 1;
            subA = true;
            cout << "Aの補数:" << a << endl;
        }
        if (bitsetB.test(31))
        {
            b = ~b + 1;
            subB = true;
            cout << "Bの補数:" << b << endl;
        }
        sum = adder(a, b, subA, subB);
        return sum;
    }
};

int main()
{
    Solution s;
    int ans = s.getSum(100, 12);
    cout << ans << ":" << bitset<32>(ans) << endl;
}