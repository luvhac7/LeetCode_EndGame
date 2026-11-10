typedef long long ll;
class Solution {
public:
    ll solve(vector<int>a,int n)
    {
        /*ll res=0;
        for(int i=1;i<n;i++)
            {
                ll sum=pow(a[i-1]-a[i],2);
                res+=sum;
            }
        return res;
        */
        vector<ll>dp(n+1,LLONG_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)

                {
                    int prv=i-j;
                    if(prv>=0)
                    {
                        dp[i]=min(dp[i],dp[prv]+a[i-1]+(ll)j*j);
                    }
                }
        }
            return dp[n];
    }
    
    int climbStairs(int n, vector<int>& costs) {
        
        return (int)solve(costs,n);
        
    }
};