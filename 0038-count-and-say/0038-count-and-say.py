class Solution:
    def countAndSay(self, n: int) -> str:
        cur = "1"
        
        # Base case is n = 1 ("1"), so loop n - 1 times
        for _ in range(n - 1):
            next_seq = ""
            count = 1
            N = len(cur)
            
            for i in range(1, N):
                if cur[i] == cur[i - 1]:
                    count += 1
                else:
                    next_seq += str(count) + cur[i - 1]
                    count = 1
            
            # Append the last character group
            next_seq += str(count) + cur[N - 1]
            cur = next_seq
            
        return cur