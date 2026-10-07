class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        t=l=0
        b=len(matrix)-1
        r=len(matrix[0])-1
        ans =[]
        while l<=r and t<=b:
            # left to right top constant
            for i in range(l,r+1):
                ans.append(matrix[t][i])
            t +=1
            # top to bottum right constant
            for i in range(t,b+1):
                ans.append(matrix[i][r])
            r -=1
            # right to left buttom constant
            if t<=b:
                for i in range(r,l-1,-1):
                    ans.append(matrix[b][i])
                b -=1
            if l<=r:
                for i in range(b,t-1,-1):
                    ans.append(matrix[i][l])
                l +=1
        return ans

        