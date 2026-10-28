class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        n=len(nums)
        for i in range(n-1):
            for j in range(n):
                if nums[i]+nums[j]==target and i!=j:
                    return [i,j]
        return -1
