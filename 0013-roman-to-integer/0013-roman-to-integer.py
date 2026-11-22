class Solution:
    def romanToInt(self, s: str) -> int:
        # Your code goes here
        ans =0
        d={
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        for ch in range(len(s)):
            if ch<len(s)-1 and d[s[ch]]<d[s[ch+1]]:
                ans -=d[s[ch]]
            else:
                ans +=d[s[ch]]
        return ans
