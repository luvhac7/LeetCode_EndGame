class Solution:
    def stoneGameII(self, a: List[int]) -> int:
        for i in range(len(a)-2,-1,-1):
            a[i]+=a[i+1]
        @cache
        def f(i,x):
            if i+x*2>=len(a):
                return a[i]
            return a[i]-min(f(i+j,max(x,j)) for j in range(1,x*2+1))
        return f(0,1)
        