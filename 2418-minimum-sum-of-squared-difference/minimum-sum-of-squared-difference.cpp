class Solution {
public:
typedef long long ll;
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        vector<int>d(100001,0);
        ll k=(ll)k1+k2,sum=0;
        int mx=0;
        for(int i=0;i<a.size();i++){
            int x=abs(a[i]-b[i]);
            d[x]++;
            sum+=x;
            mx=max(mx,x);
        }
        if(sum<=k) return 0;
        for(int i=mx;i>0&&k>0 ;i--){
            ll move=min(k,(ll)d[i]);
            d[i]-=move;
            d[i-1]+=move;
            k-=move;
        }
        ll ans=0;
        for(int i=0;i<=mx;i++) ans+=(ll) i*i*d[i];
        return ans;
    }
};