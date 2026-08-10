class Solution:
    M=10**5
    dp=[False]*(M+1)
    for i in range(M+1):
        if dp[i]: continue
        for j in range(1,isqrt(M-i)+1):
            dp[i+j**2]=True
    def winnerSquareGame(self, n: int) -> bool:
        return self.dp[n]