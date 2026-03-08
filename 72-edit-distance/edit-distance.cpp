class Solution {
public:
int dp[505][505];
int f(string &a,string &b,int m,int n ){
    if(n==0) return m;if(m==0) return n;
    if(dp[m][n]!=-1) return dp[m][n];
    if(a[m-1]==b[n-1])
        return dp[m][n]=f(a,b,m-1,n-1);
    return dp[m][n]=1+min({f(a,b,m-1,n),f(a,b,m,n-1),f(a,b,m-1,n-1)});
  //  return a[m-1]==b[n-1] ? f(a,b,m-1,n-1):1+min({f(a,b,m-1,n),f(a,b,m,n-1),f(a,b,m-1,n-1)});
}
    int minDistance(string a, string b) {
        memset(dp,-1,sizeof(dp));
        return f(a,b,a.size(),b.size());
    }
};