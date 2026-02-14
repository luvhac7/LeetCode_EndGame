class Solution {
public:
typedef double d;
    double champagneTower(int p, int r, int q) {
        d dp[101][101]={0.0};
        dp[0][0]=p;
        for(int i=0;i<=r;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(dp[i][j]>1)
                {
                    d x=(dp[i][j]-1)/2.0;
                    dp[i][j]=1;
                    dp[i+1][j]+=x;
                    dp[i+1][j+1]+=x;
                }

            }
        
        }
    return dp[r][q];
    }
};