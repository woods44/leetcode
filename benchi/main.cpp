#include <random>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
#include <time.h>
#include <set>
using namespace std;

void sortTime()
{
    random_device rnd;
    vector<int> nums;
    int vecSize = pow(10, 4);
    for (int i = 0; i < vecSize; ++i)
    {
        nums.emplace_back(rand());
    }
    clock_t start = clock();
    sort(nums.begin(), nums.end());
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    cout << "VecSize:" << vecSize << " SortTime:" << time << "[s]" << endl;
}

void threeSum(vector<int> &nums)
{
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());
    clock_t start = clock();
    for (int left = 0; left < nums.size(); left++)
    {
        int mid = left + 1;
        int right = nums.size() - 1;
        while (mid < right)
        {
            int sum = nums[left] + nums[right] + nums[mid];
            if (sum == 0)
            {
                ans.insert({nums[left], nums[mid], nums[right]});
                right--;
                mid++;
            }
            else if (sum < 0)
            {
                mid++;
            }
            else
            {
                right--;
            }
        }
    }
    vector<vector<int>> output(ans.begin(), ans.end());
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "3SumTime:" << time << "[ms]" << endl;
    return;
}

void pointerThreeSum(vector<int> &nums)
{
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());
    clock_t start = clock();
    auto left = nums.begin();
    while (left < nums.end())
    {
        auto mid = left + 1;
        auto right = nums.end() - 2;
        while (mid < right)
        {
            int sum = *left + *right + *mid;
            if (sum == 0)
            {
                ans.insert({*left, *mid, *right});
                right--;
                mid++;
            }
            else if (sum < 0)
            {
                mid++;
            }
            else
            {
                right--;
            }
        }
        left++;
    }
    vector<vector<int>> output(ans.begin(), ans.end());
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    cout << "3SumTime:" << time << "[ms]" << endl;
    return;
}

int main()
{
    sortTime();
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    threeSum(nums);
    pointerThreeSum(nums);
}