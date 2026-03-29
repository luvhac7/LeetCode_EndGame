class Solution(object):
    def permute(self, a):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[]
        def back(p,u):
            if len(p)==len(u):
                res.append(p[:])
                return 
            for i in range(len(a)):
                if u[i]:
                    continue
                u[i]=True
                p.append(a[i])
                back(p,u)
                p.pop()
                u[i]=False
        back([],[False]*len(a))
        return res        