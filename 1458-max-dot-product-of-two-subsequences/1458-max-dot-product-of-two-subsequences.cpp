class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int x=a.size(),y=b.size();
        vector<vector<int>>dp(x+1,vector<int>(y+1,INT_MIN));
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                int ans=a[i-1]*b[j-1];
                dp[i][j]=max(
                    {
                        ans,
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]==INT_MIN ? INT_MIN:dp[i-1][j-1]+ans
                    }
                );
            }
        }
        return dp[x][y];
    }
};