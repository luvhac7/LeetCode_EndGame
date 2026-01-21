class Solution {
public:
typedef long long ll;
const int mod =1e9+7;
typedef __int128 it;
    int maximumXorProduct(long long a, long long b, int n) {
        for(int i=n-1;i>=0;i--)
        {
            ll x=1LL<<i;
            ll ax=a^x,bx=b^x;
            if((it)a*b<(it)ax*bx){
                a=ax;b=bx;
            }

        }
        return (a%mod)*(b%mod)%mod;
    }
};