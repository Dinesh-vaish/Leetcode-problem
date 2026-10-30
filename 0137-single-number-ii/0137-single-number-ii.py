class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        freq ={}
        for num in nums:
            freq[num] =freq.get(num,0)+1
        for num, count in freq.items():
            if count ==1:
                return num
        return [-1]
        






















    # froces approch 
        # n =len(nums)

        # for i in range(n):
        #     count =0
        #     for j in range(n):
        #         if nums[i]==nums[j]:
        #             count +=1
        #     if count==1:
        #         return nums[i]
        # return -1