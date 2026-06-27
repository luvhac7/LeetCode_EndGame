class Solution {
public:
typedef long long ll;
typedef vector<bool> vb;
bool f(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
    int largestPrime(int n) {
        vb p(n+1,true);
        p[0]=p[1]=false;
        for(ll i=2;i<=n;i++)
        {
        if(p[i])
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                p[j]=false;
            }
        }
        }
        //for(int i:p) cout<<i<<" ";
        int cs=0,ans=0;
        for(int i=2;i<=n;i++)
        {
            if(!p[i]) continue;
            cs+=i;
            if(cs>n) break;
            if(p[cs]) ans=cs;
        }
        return ans;
    }
};