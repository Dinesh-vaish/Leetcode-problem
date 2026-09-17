class Solution(object):

    def maxProfit(self, a):

        mini=a[0]
        maxP=-1

        profit=0

        for i in range(0,len(a)):

            if(a[i]<mini):

                mini=a[i]

            else:

                profit=a[i]-mini

                maxP=max(maxP,profit)

        return maxP