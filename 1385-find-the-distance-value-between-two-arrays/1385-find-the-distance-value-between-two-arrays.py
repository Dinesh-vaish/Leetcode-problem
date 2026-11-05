class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        count =0
        for i in range(len(arr1)):
            allvalid =True
            for j in range(len(arr2)):
                if abs(arr1[i]-arr2[j])<=d:
                    allvalid =False
                    break
            if allvalid:
                count+=1
        return count
            