class Solution {
public:
typedef long long ll;
    int mirrorDistance(int n) {
        ll res=0;
        for(int i=n;i;i/=10)
        {
            res=10*res+i%10;
        }
        res-=n;
        return res>=0 ? res:-res;
    }
};