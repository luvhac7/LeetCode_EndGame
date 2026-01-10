class Solution {
public:
typedef const int I;
    string lexicographicallySmallestString(string s) {
        I n=s.size();
        vector<vector<string>>dp(n+1,vector<string>(n+1));
        for(int d=1;d<=n;d++)
        {
            for(int i=0;i+d<=n;i++)
            {
                I j=i+d;
                string minstr=s[i]+dp[i+1][j];
                for(int k=i+1;k<j;k++)
                {
                    if(iscons(s[i],s[k])&& dp[i+1][k].empty())
                    {
                        minstr=min(minstr,dp[k+1][j]);
                    }
                
                    
                }    dp[i][j]=minstr;
            }

        }

return dp[0][n];
            }
            bool iscons(char a,char b)
            {
                return abs(a-b) ==1|| abs(a-b)==25;
            }
};