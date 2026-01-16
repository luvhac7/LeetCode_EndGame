class Solution {
public:
unordered_map<string,bool>dp;
bool f(string a,string b)
{
    if(a==b) return true;
    if(a.size()!=b.size()) return false;
    string k=a+"#"+b;
    if(dp.count(k))return dp[k];
    string x=a,y=b;
    sort(x.begin(),x.end());sort(y.begin(),y.end());
    if(x!=y)return dp[k]=false;
    int n=a.size();
    for(int i=1;i<n;i++)
    {
    if(f(a.substr(0,i),b.substr(0,i)) && f(a.substr(i),b.substr(i)) || f(a.substr(0,i),b.substr(n-i)) && f(a.substr(i),b.substr(0,n-i))){
        return dp[k]=true;
    }   
    }
    return dp[k]=false;
    
}
    bool isScramble(string s1, string s2) {
        return f(s1,s2);
    }
};