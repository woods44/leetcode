using System.ComponentModel;
/*
 * @lc app=leetcode id=22 lang=csharp
 *
 * [22] Generate Parentheses
 */
using System.Collections.Generic;
// @lc code=start
public class Solution
{
    List<string> result = new List<string>();
    public void BackTrack(int r, int remain, string pattern)
    {
        if (r == 0)
        {
            for (int i = 0; i < remain; ++i)
            {
                pattern += ")";
            }
            result.Add(pattern);
            return;
        }
        pattern += "(";
        this.BackTrack(r - 1, remain + 1, pattern);
        pattern = pattern[..^1];
        pattern += ")";
        this.BackTrack(r, remain, pattern);
    }
    public IList<string> GenerateParenthesis(int n)
    {
        this.BackTrack(n, 0, "");
        return result;
    }
}
// @lc code=end