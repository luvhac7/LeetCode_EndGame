class Solution {
public:
typedef long long ll;
    vector<int> gcdValues(vector<int>& a, vector<long long>& q) {
        int mx=ranges::max(a);
        vector<int>f(mx+1,0);
        vector<ll>gcd(mx+1,0);
        for(int &i:a) f[i]++;
        for(int i=mx;i>0;i--)
        {
            ll sm=0,extra=0;
            for(int j=i;j<=mx;j+=i)
            {
                sm+=f[j],extra+=gcd[j];
            }
            gcd[i]=sm*(sm-1)/2-extra;
        }
        partial_sum(gcd.begin(),gcd.end(),gcd.begin());
        vector<int>res(q.size());
        for(int i=0;i<q.size();i++) res[i]=ranges::upper_bound(gcd,q[i])-gcd.begin();

        return res;
    }
};