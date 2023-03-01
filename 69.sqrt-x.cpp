/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long y = 0;
        while (1)
        {
            long tmp = y * y;
            if (tmp > x)
            {
                return y - 1;
            }
            y++;
        }
        return -1;
    }
};
// @lc code=end
