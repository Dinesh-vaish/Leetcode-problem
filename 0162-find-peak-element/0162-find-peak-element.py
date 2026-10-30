
class Solution:
    def findPeakElement(self, nums: list[int]) -> int:

        n = len(nums)

        for i in range(n):

            left = (i == 0 or nums[i] > nums[i - 1])
            right = (i == n - 1 or nums[i] > nums[i + 1])

            if left and right:
                return i

        return -1
