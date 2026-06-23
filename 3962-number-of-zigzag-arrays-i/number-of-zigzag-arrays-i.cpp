class Solution {
public:
int M=1e9+7;
typedef long long ll;
int f(int n,int l,int r)
{
int m=r-l+1;
vector<ll>dp(m,1);
while(--n)
{
    reverse(dp.begin(),dp.end());
    ll pre=0;
    for(auto &x:dp)
    {
    ll cur=x;
    x=pre;
    pre=(pre+cur)%M;
    }
}
ll ans=0;
for(auto x:dp)ans=(ans+x)%M;
return (ans*2)%M;
}
    int zigZagArrays(int n, int l, int r) {
    return f(n,l,r);
    }
};