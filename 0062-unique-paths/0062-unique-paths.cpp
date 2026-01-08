class Solution {
public:

    int solve(int m,int n,vector<vector<int>>&dp){
        if(n==1 || m==1)
        {
            return dp[m][n]=1;
        }
        if(dp[m][n]==0)
        {
            dp[m][n]=solve(m-1,n,dp)+solve(m,n-1,dp);
        }
        return dp[m][n];
    }
    int help(int m,int n)
    {
         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         int ans=solve(m,n,dp);
         return ans;

    }
    int uniquePaths(int m, int n) {
        return help(m,n);
    }
};