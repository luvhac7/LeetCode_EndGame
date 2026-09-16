class Solution {
public:
int mod=1e9+7;
vector<vector<vector<int>>>dp;
    int func(int n,int k,int ind,bool open){
        if(k==0)return 1;
        if(ind==n)return 0;
        int ans=0;
        if(dp[k][ind][open]!=-1)return dp[k][ind][open];
        if(open){
            ans+=func(n,k,ind+1,open);
            ans+=func(n,k-1,ind,false);
        }
        else{
            ans+=func(n,k,ind+1,false);
            ans+=func(n,k,ind+1,true);
        }
        return dp[k][ind][open]=ans%mod;
    }

    int numberOfSets(int n, int k) {
        dp.assign(k+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return func(n,k,0,false);
    }
};