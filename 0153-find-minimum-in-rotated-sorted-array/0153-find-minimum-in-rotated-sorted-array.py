class Solution:
    def findMin(self, nums: list[int]) -> int:
        mini =nums[0]
        for i in nums:
            if i<mini:
                mini =i
        return mini
        