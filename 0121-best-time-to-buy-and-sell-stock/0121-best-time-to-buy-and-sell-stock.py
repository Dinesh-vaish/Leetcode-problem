class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price=prices[0]
        maxProfit =0

        for i in prices:
            min_price =min(min_price,i)
            profit =i-min_price
            maxProfit =max(profit,maxProfit)
        return maxProfit

        