class Solution {
public:
typedef long long ll;
    int numOfWays(int n) {
        const int m=1e9+7;
        ll a=6,b=6;
        for(int i=2;i<=n;i++){
            ll aa=(a*2+2*b)%m;
            ll bb=(2*a+3*b)%m;
            a=aa;
            b=bb;
        }
        return (a+b)%m;
    }
};