class Solution(object):
    def change(self, amt, a):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        dp=[0]*(amt+1)
        dp[0]=1
        for coin in a:
            for i in range(coin,amt+1):
                dp[i]+=dp[i-coin]
        return dp[amt]

        