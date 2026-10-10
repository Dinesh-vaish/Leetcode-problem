class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_pr =prices[0]
        profit = 0

        for i in prices:
            min_pr =min(min_pr,i)
            profit =max(profit,i-min_pr)
        return profit

        