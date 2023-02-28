#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
class KthLargest
{
public:
    multiset<int> n;
    int k;
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        this->n = multiset<int>(nums.begin(), nums.end());
    }

    int add(int val)
    {
        this->n.insert(val);
        auto it = this->n.end();
        --it;
        for (int i = 0; i < this->k - 1; ++i)
        {
            --it;
        }
        return *it;
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */