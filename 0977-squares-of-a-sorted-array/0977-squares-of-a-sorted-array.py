class Solution(object):

    def sortedSquares(self, a):
        n=len(a)
        res=[0]*n
        left=0
        right=n-1
        for i in range(n-1,-1,-1):
            if abs(a[left])> abs(a[right]):
                res[i]=a[left]*a[left]
                left+=1
            else:
                res[i]=a[right]*a[right]
                right-=1
        return res