class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        rows,cols = len(coins),len(coins[0])
        @cache
        def dfs(r,c,count):
            if r == rows or c == cols:
                return float("-inf")
            val = coins[r][c]

            if r == rows -1 and c == cols - 1:
                if val >= 0:
                    return val
                else:
                    if count < 2:
                        return 0
                    else:
                        return val
            res = float("-inf")
            res = max(res,dfs(r + 1,c,count) + val)
            res = max(res,dfs(r,c + 1,count) + val)

            if val < 0 and count < 2:
                res = max(res,dfs(r,c + 1,count + 1) + 0)
                res = max(res,dfs(r + 1,c,count + 1) + 0)
            return res
        r = dfs(0,0,0)
        dfs.cache_clear()
        return r