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
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        auto left = numbers.begin();
        auto right = numbers.end();
        bool isRightSearch = true;
        while (true)
        {
            cout << "Left:" << distance(numbers.begin(), left) << "right:" << distance(numbers.begin(), right) << endl;
            auto minNum = *left + *right;
            if (minNum == target)
            {
                vector<int> ans{(int)distance(numbers.begin(), left) + 1, (int)distance(numbers.begin(), right) + 1};
                return ans;
            }
            if (minNum < target)
            {
                left++;
            }
            if (minNum > target)
            {
                right--;
            }
        }
        vector<int> ans{-1, -1};
        return ans;
    }
};

template <class T>
void vectorPrint(vector<T> &vec)
{
    for (auto &a : vec)
    {
        cout << a;
        if (&a != &vec.back())
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<int> numbers{-1, -1, -1, -1, 1, 1};
    int target = 2;
    Solution solution;
    vector<int> ans = solution.twoSum(numbers, target);
    vectorPrint(ans);
}