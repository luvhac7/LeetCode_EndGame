class Solution:
    def maximumJumps(self, a: List[int], tar: int) -> int:
        @cache
        def sol(i):
            if i==0: return 0
            ans=-inf
            for j in range(i):
                if abs(a[j]-a[i])<=tar:
                    ans=max(ans,1+sol(j))
            return ans
        ans=sol(len(a)-1)
        return -1 if ans<0 else ans