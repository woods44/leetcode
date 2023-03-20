#
# @lc app=leetcode id=9 lang=python3
#
# [9] Palindrome Number
#

# @lc code=start
class Solution:
    def reverse(self, l: int, r: int, x: str):
        while True:
            if l < 0:
                break
            if r >= len(x):
                break
            if x[l] != x[r]:
                return False
            l -= 1
            r += 1
        if l == -1 and r == len(x):
            return True
        return False

    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        rx = x[::-1]
        return rx == x
        # if len(x) % 2 == 0:
        #     return self.reverse(int(len(x) / 2) - 1, int(len(x) / 2), x)
        # return self.reverse(int(len(x) / 2), int(len(x) / 2), x)


# @lc code=end
s = Solution()
s.isPalindrome("10201")
