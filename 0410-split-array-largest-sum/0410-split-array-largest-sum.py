class Solution(object):
    def splitArray(self, a, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def can(maxi):
            part=1
            s=0
            for i in a:
                if s+i>maxi:
                    part+=1
                    s=i
                else: s+=i
            return part<=k
        l,r=max(a),sum(a)
        while l<r:
            mid=(l+r)//2
            if can(mid):
                r=mid
            else:
                l=mid+1
        return l