class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10**9 + 7

        even_count = 1  # Empty prefix sum
        odd_count = 0

        prefix_sum = 0
        ans = 0

        for num in arr:
            prefix_sum += num

            if prefix_sum % 2 == 0:
                ans = (ans + odd_count) % MOD
                even_count += 1
            else:
                ans = (ans + even_count) % MOD
                odd_count += 1

        return ans
