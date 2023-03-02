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
            if (node != nullptr)
            {
                i1 = node->val;
            }
            if (node2 != nullptr)
            {
                i2 = node2->val;
            }
            if (node == nullptr && node2 == nullptr)
            {
                if (c > 0)
                {
                    ListNode *tmp = new ListNode(c);
                    pAns->next = tmp;
                }
                break;
            }
            int total = i1 + i2 + c;
            int val = (total % 10);
            c = total / 10;
            ListNode *tmp = new ListNode(val);
            if (ans == nullptr)
            {
                ans = tmp;
            }
            if (pAns != nullptr)
            {
                pAns->next = tmp;
            }
            pAns = tmp;
            if (node != nullptr)
            {
                node = node->next;
            }
            if (node2 != nullptr)
            {
                node2 = node2->next;
            }
        }
        // ListNode *p = ans;
        // while (p != nullptr)
        // {
        //     cout << p->val << ", ";
        //     p = p->next;
        // }
        // cout << endl;
        return ans;
    }
};
// int main()
// {
//     ListNode tmp = ListNode(3);
//     ListNode tmp2 = ListNode(4, &tmp);
//     ListNode tmp3 = ListNode(2, &tmp2);

//     ListNode tmp4 = ListNode(3);
//     ListNode tmp5 = ListNode(4, &tmp4);
//     ListNode tmp6 = ListNode(2, &tmp5);
//     Solution s;
//     s.addTwoNumbers(&tmp3, &tmp6);

//     return 0;
// }
// @lc code=end
