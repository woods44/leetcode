/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        stack<pair<TreeNode *, int>> bfs;
        bfs.push(pair<TreeNode *, int>(root, 0));
        while (!bfs.empty())
        {
            pair<TreeNode *, int> tmp = bfs.top();
            bfs.pop();
            // cout << tmp.first->val << endl;
            tmp.second += tmp.first->val;
            if (tmp.first->left != nullptr)
            {
                bfs.push(pair<TreeNode *, int>(tmp.first->left, tmp.second));
            }
            if (tmp.first->right != nullptr)
            {
                bfs.push(pair<TreeNode *, int>(tmp.first->right, tmp.second));
            }
            if (tmp.first->right == nullptr && tmp.first->left == nullptr)
            {
                if (tmp.second == targetSum)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
