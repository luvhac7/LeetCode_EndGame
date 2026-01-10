class Solution {
public:
    bool solve(char a,char b)
    {
        return abs(a-b)==1 || abs(a-b)==25;
    }
    string lexicographicallySmallestString(string s) {
        int n=s.size();
        vector<vector<string>>dp(n+1,vector<string>(n+1));
        for(int d=1;d<=n;d++)
        {
            for(int i=0;i+d<=n;i++)
            {
                int j=i+d;
                string ans=s[i]+dp[i+1][j];
                for(int k=i+1;k<j;k++)
                {
                    if(solve(s[i],s[k])&& dp[i+1][k].empty())
                    {
                        ans=min(ans,dp[k+1][j]);
                    }
                }
                dp[i][j]=ans; 
            }
        }
        return dp[0][n];
    }
};