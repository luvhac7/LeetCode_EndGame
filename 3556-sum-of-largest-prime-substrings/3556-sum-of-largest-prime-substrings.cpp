class Solution {
public:
typedef long long ll;
set<ll,greater<ll>>st;
bool pr(ll n)
{
    if(n<2) return false;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
    long long sumOfLargestPrimes(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int len=1;i+len<=n;len++)
            {
                string sub=s.substr(i,len);
                ll val=stoll(sub);
                if(pr(val))
                {
                    st.insert(val);
                }
            }
        }
        ll ts=0;
        int cnt=0;
        for(ll i:st)
        {
            if(cnt>=3) break;
            ts+=i;
            cnt++;
        }
        return ts;
    }
};