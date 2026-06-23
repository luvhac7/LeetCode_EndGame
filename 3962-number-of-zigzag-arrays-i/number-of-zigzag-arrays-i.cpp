class Solution {
public:
int M=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        vector<int>a(m,1);
        for(int i=2;i<=n;i++)
        {
            reverse(a.begin(),a.end());
            int sum=0;
            for(auto &it:a)
            {
            sum=(sum+exchange(it,sum))%M;
        }
        }
        return ((accumulate(a.begin(),a.end(),0LL)%M)<<1)%M;
    }
};