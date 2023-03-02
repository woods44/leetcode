#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <bit>
#include <bitset>
#define SIZE_INT sizeof(uint32_t) * 8;
using namespace std;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int size = SIZE_INT;
        uint32_t a = n;
        uint32_t b = n;

        a = a & 0x55555555;
        b = b ^ a;
        a = (a << 1) | (b >> 1);

        b = a;
        a = a & 0x33333333;
        b = b ^ a;
        a = (a << 2) | (b >> 2);

        b = a;
        a = a & 0x0f0f0f0f;
        b = b ^ a;
        a = (a << 4) | (b >> 4);

        b = a;
        a = a & 0x00ff00ff;
        b = b ^ a;
        a = (a << 8) | (b >> 8);

        b = a;
        a = a & 0x0000ffff;
        b = b ^ a;
        a = (a << 16) | (b >> 16);
        return a;
    }
};

int main()
{
    Solution s;
    cout << "元のビット" << endl;
    cout << bitset<32>(12) << endl;
    cout << bitset<32>(s.reverseBits(12)) << endl;
}