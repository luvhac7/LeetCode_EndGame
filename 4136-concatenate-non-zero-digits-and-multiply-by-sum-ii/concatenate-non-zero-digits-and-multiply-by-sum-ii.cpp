class Solution {
public:
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& que) {
        string luv=s;
        int n=s.size();
        ll mod=1e9+7;
        vector<ll>pw(n+1,1);
        for(int i=1;i<=n;i++){
            pw[i]=(pw[i-1]*10)%mod;
        }
        vector<int>nz(n+1,0);
        vector<int>ds(n+1,0);
        vector<ll>pre(n+1,0);
        for(int i=0;i<n;i++){
            int d=s[i]-'0';
            if(d==0){
                nz[i+1]=nz[i];
                ds[i+1]=ds[i];
                pre[i+1]=pre[i];
            }else{
                nz[i+1]=nz[i]+1;
                ds[i+1]=ds[i]+d;
                pre[i+1]=(pre[i]*10+d)%mod;
            }
        }
        vector<int>ans;
        ans.reserve(que.size());
            for(const auto &q:que){
                int l=q[0];
                int r=q[1];
                ll cs=ds[r+1]-ds[l];
                if(cs==0){
                    ans.push_back(0);
                    continue;
                }
                int len=nz[r+1]-nz[l];
                ll x=(pre[r+1]-(pre[l]*pw[len])%mod+mod)%mod;
                ans.push_back((x*cs)%mod);
            }
        return ans;
    }
};