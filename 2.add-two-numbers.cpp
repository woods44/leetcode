/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c = 0; // 桁上がり
        ListNode *node = l1;
        ListNode *node2 = l2;
        ListNode *pAns = nullptr;
        ListNode *ans = nullptr;
        while (1)
        {
            int i1 = 0;
            int i2 = 0;
            if (node == nullptr)
            {
                i1 = 0;
            }
            if (node2 == nullptr)
            {
                i2 = 0;
            }
            if (node == nullptr && node2 == nullptr)
            {
                break;
            }
            int total = i1 + i2 + c;
            c = total / 10;
            ListNode tmp = ListNode(total % 10);
            if (ans == nullptr)
            {
                ans = &tmp;
            }
            if (pAns != nullptr)
            {
                pAns->next = &tmp;
            }
            cout << ans->val << endl;
            pAns = &tmp;
            node = node->next;
            node2 = node2->next;
        }
        ListNode *p = ans;
        while (p != nullptr)
        {
            cout << p->val << ", ";
            p = p->next;
        }
        cout << endl;
        return ans;
    }
};
// int main()
// {
//     return 0;
// }
// @lc code=end
