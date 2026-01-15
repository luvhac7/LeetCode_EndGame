class Solution {
public:
    int numSubseq(vector<int>& a, int t) {
        int n=a.size();
        sort(a.begin(),a.end()); 
        int res=0,l=0,r=n-1,M=1e9+7;
        vector<int>p(n,1);
        for(int i=1;i<n;i++)
        {
            p[i]=p[i-1]*2%M;
        }
        while(l<=r)
        {
            if(a[l]+a[r]>t)
            {
                r--;
            }
            else{
                res=(res+p[r-l++])%M;
            }
        }
        return res;
    }
};