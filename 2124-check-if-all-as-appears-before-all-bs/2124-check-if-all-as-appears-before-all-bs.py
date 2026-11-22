class Solution:
    def checkString(self, s: str) -> bool:
        i=0
        while i<len(s) and s[i]=='a':
            i+=1
        while i<len(s):
            if s[i]=='a':
                return False
            i+=1
        return True
        