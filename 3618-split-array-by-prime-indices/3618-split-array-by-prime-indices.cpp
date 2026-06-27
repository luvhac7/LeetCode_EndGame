class Solution {
public:
typedef long long ll;
bool f(ll n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
    long long splitArray(vector<int>&a) {
        int n=a.size();ll x=0,y=0;
        for(ll i=0;i<a.size();i++)
        {
            if(f(i))x+=a[i];
            else y+=a[i];
        }
        return abs(x-y);
    }
};