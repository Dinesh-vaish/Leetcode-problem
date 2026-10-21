class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m=len(haystack)
        n=len(needle)
        for i in range(m-n+1):
            if haystack[i:i+n]==needle:# 0:3
                return i
        return -1


        