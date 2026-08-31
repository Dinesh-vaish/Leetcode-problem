class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        N = len(mat)
        sumD = 0
        
        for i in range(N):
            # Add primary diagonal element
            sumD += mat[i][i]
            # Add secondary diagonal element
            sumD += mat[i][N - 1 - i]
        
        # If matrix size is odd, subtract the double-counted center element
        if N % 2 != 0:
            sumD -= mat[N // 2][N // 2]
            
        return sumD