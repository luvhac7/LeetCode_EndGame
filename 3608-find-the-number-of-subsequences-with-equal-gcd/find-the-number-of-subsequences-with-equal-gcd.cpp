class Solution {
public:
    int dp[201][201][201];
    int n;
    vector<int>a;
    int MOD=1e9+7;
    int rec(int i,int gcd1,int gcd2)
    {
        if(i==n)
        {
            if(gcd2!=0&&gcd1==gcd2)return 1;
            return 0;
        }    
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];
        int ans=(rec(i+1,gcd(gcd1,a[i]),gcd2)+rec(i+1,gcd1,gcd(gcd2,a[i])))%MOD;
        ans+=+rec(i+1,gcd1,gcd2);
        ans%=MOD;
        return dp[i][gcd1][gcd2]=ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        a=nums;
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0);
    }
};