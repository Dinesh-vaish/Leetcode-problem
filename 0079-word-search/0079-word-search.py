class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:


        def dfs(i,j,k):
            if k==len(word):
                return True
            if (i<0 or j<0 or i>=m or j>=n or board[i][j] !=word[k]):
                return False
            ch =board[i][j]
            board[i][j]="#"

            found =(
                dfs(i+1,j,k+1) or
                dfs(i-1,j,k+1) or
                dfs(i,j+1,k+1) or
                dfs(i,j-1,k+1)
            )
            board[i][j] =ch
            return found


        m =len(board)
        n =len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j]==word[0]:
                    if dfs(i,j,0):
                        return True
        return False