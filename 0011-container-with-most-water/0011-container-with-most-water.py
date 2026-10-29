class Solution:
    def maxArea(self, height: list[int]) -> int:
        l =0
        r=len(height)-1
        mw =0
        area =0
        while l<r:
            width =r-l
            h =min(height[l],height[r])
            area =width*h
            mw =max(mw,area)
            if height[l]<height[r]:
                l+=1
            else:
                r -=1
        return mw
        