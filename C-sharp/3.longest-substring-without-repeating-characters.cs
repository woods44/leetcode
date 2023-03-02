using System.Collections.Generic;
/*
 * @lc app=leetcode id=3 lang=csharp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        if (s == "")
        {
            return 0;
        }
        int left = 0;
        int right = 1;
        int max = 1;
        int count = 1;
        HashSet<char> box = new HashSet<char>();
        box.Add(s[left]);
        while (right < s.Length)
        {
            if (box.Contains(s[right]))
            {
                count = 1;
                left++;
                right = left + 1;
                box.Clear();
                box.Add(s[left]);
                continue;
            }
            box.Add(s[right]);
            count++;
            right++;
            if (max < count)
            {
                max = count;
            }
        }
        return max;
    }
}
// @lc code=end
