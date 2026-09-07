class Solution {
public:
typedef long long ll;
ll M=1e9+7;
    int distinctSubseqII(string s) {
        ll r=1;
        vector<ll>a(26,0);
        for(char x:s){
            int i=x-'a';
            ll o=r;
            r=(2*r-a[i]+M)%M;
            a[i]=o;
        }
        return (r-1+M)%M;
    }
};