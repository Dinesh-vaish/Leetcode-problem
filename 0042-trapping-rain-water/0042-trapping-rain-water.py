class Solution:
    def trap(self, height: list[int]) -> int:
        n =len(height)
        left =0
        right =n-1
        left_max =0
        right_mx =0
        water =0


        while left < right:
            if height[left]<height[right]:
                if height[left]>=left_max:
                    left_max=height[left]
                else:
                    water += left_max - height[left]

                left+=1

            else:
                if height[right]>=right_mx:
                    right_mx =height[right]
                else:
                    water += right_mx -height[right]
                right -=1
        return water
        