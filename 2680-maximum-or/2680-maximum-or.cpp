class Solution {
public:
typedef long long ll;

    long long maximumOr(vector<int>& a, int k) {
        int n=a.size();
       vector<int>pre(n+1,0),suf(n+1,0);
       for(int i=0;i<n;i++) pre[i+1]=pre[i]|a[i];
       for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]|a[i];
       ll ans=0;
       for(int i=0;i<n;i++)
       {
        ll p=1LL<<k;
        ll cur=pre[i]|(p*1LL*a[i])|suf[i+1];
        ans=max(ans,cur);
       }
       return ans;

    }
};