class Solution:
    def productExceptSelf(self, a: List[int]) -> List[int]:
        res=[1]*(len(a))
        pre=1
        for i in range(len(a)):
            res[i]=pre
            pre*=a[i]
        post=1
        for i in range(len(a)-1,-1,-1):
            res[i]*=post
            post*=a[i]
        return res