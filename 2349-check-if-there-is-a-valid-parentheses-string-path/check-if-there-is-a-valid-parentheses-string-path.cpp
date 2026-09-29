class Solution {
public:
    bool hasValidPath(vector<vector<char>>& a) {
        int n=a.size(); int m=a[0].size();
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(m+n+2,false)));
        if (a[0][0]=='(') dp[0][0][1]=true;
        else return false;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (i==0 && j==0) continue;
                for (int k=0;k<m+n;k++){
                    if (a[i][j]=='('){
                        if (k==0) continue;
                        if (i>0) dp[i][j][k]=dp[i-1][j][k-1];
                        if (j>0) dp[i][j][k]=(dp[i][j][k]||dp[i][j-1][k-1]);
                    }
                    else if (a[i][j]==')'){
                        if (i>0) dp[i][j][k]=dp[i-1][j][k+1];
                        if (j>0) dp[i][j][k]=(dp[i][j][k]||dp[i][j-1][k+1]);
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};