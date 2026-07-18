class Solution(object):
    def findGCD(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mn = min(nums)
        mx = max(nums)

        while mx != 0:
            mn, mx = mx, mn % mx

        return mn