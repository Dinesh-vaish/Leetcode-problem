class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        for i in range(len(nums)):
            nums[i]=abs(nums[i]*nums[i])
        nums.sort()
        return nums
        