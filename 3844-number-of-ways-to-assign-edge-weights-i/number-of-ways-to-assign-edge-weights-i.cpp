class Solution {
public:
static const int M=1e9+7;
typedef long long ll;
ll poww(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%M;
        }
        a=(a*a)%M;
        b>>=1;
    }
    return ans;
}
    int assignEdgeWeights(vector<vector<int>>& a) {
     int n=a.size()+1;
     vector<vector<int>>ad(n+1);
     for(auto &e:a){
        int u=e[0],v=e[1];
        ad[u].push_back(v);
        ad[v].push_back(u);
     }   
     queue<pair<int,int>>q;
     vector<bool>vis(n+1,false);
     q.push({1,0});
     vis[1]=true;
     int maxi=0;
     while(!q.empty())
     {
        auto [node,depth]=q.front();
        q.pop();
        maxi=max(maxi,depth);
        for(int it:ad[node]){
            if(!vis[it]){
                vis[it]=true;
                q.push({it,depth+1});
            }
        }
     }
     return (int)poww(2,maxi-1);
    }
};