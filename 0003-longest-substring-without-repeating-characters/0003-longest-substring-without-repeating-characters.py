class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cset =set()
        Max_len =0
        left =0
        for right in range(len(s)):
            while s[right] in cset:
                cset.remove(s[left])
                left += 1
            cset.add(s[right])
            Max_len =max(Max_len,right-left+1)
        return Max_len

            


        