class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        arr =[]
        ans =[]
        def backtrack(start):
            ans.append(arr.copy())
            for i in  range(start,len(nums)):
                if i > start and  nums[i]==nums[i-1]:
                    continue
                arr.append(nums[i])
                backtrack(i+1)
                arr.pop()
        backtrack(0)
        return ans
            

        