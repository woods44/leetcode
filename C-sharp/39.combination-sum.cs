/*
 * @lc app=leetcode id=39 lang=csharp
 *
 * [39] Combination Sum
 */

// @lc code=start
public class Solution
{
    public IList<IList<int>> result;
    public void recomb(int i, int r, int[] candidates, int target, List<int> pattern)
    {
        var sum = pattern.Sum();
        Console.WriteLine($"{i}, {r}, {sum}");
        if (sum == target)
        {
            this.result.Add(new List<int>(pattern));
        }
        if (sum > target)
        {
            return;
        }
        if (r > candidates.Length - 1)
        {
            return;
        }
        for (int idx = i; idx < candidates.Length; idx++)
        {
            pattern.Add(candidates[idx]);
            recomb(idx, r + 1, candidates, target, pattern);
            pattern.RemoveAt(0);
        }
    }
    public IList<IList<int>> CombinationSum(int[] candidates, int target)
    {
        this.result = new List<IList<int>>();
        var pattern = new List<int>();
        recomb(0, 0, candidates, target, pattern);
        return this.result;
    }
}
// @lc code=end
public class Combination
{
    static void Main(string[] args)
    {
        Solution s = new Solution();
        int[] candidates = { 2, 3, 6, 7 };
        var result = s.CombinationSum(candidates, 7);
        Console.WriteLine(result);
    }
}
