class Solution {
public:
typedef long long ll;
    long long maxPairStrength(vector<int>& a) {
        ll st=0;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                ll x=a[i],y=a[j];
                ll g=gcd(x,y);
                ll str=(x/g)*(y/g);
                if(str>st)st=str;
            }
        }
        return st;
    }
};