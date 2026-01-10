class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<s1.size();i++)
        {
            for(int j=0;j<s2.size();j++)
            if(s1[i]==s2[j])
            {
                dp[i+1][j+1]=dp[i][j]+s1[i];
            }
            else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        int ans=0;
        for(char c:s1)ans+=c;
        for(char c:s2)ans+=c;
        return ans-2*dp[n][m];
    }
};