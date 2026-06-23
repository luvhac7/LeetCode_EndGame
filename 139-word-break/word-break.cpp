class Solution {
public:
bool solve(string s,vector<string>&a,int i)
{
    int n=s.size();
//     if(n==i) return true;
//     string pre="";
//     for(int j=i;j<n;j++){
//         pre+=s[j];
//         if(find(a.begin(),a.end(),pre)!=a.end()&&solve(s,a,j+1)) return true;
//     }
// return false;
// //    int j=i;
set<string>st(a.begin(),a.end());
vector<bool>dp(n+1,false);
dp[0]=true;
for(int i=1;i<=n;i++)
{
    for(int j=0;j<i;j++)
    {
    if(dp[j] && st.find(s.substr(j,i-j))!=st.end()){
        dp[i]=true;
        break;
    }
    }
}
return dp[n];
}
    bool wordBreak(string s, vector<string>&a) {
        return solve(s,a,1);
    }
};