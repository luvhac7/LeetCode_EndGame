class Solution {
public:
typedef long long ll;
vector<int>per,depth;
vector<vector<int>>up;
int L=20;
const int M=1e9+7;
int pow(ll a,ll b){
    ll ans=1;
    a%=M;
    while(b){
        if(b&1) ans=(ans*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return (int) ans;
}
int way(int d){
    if(d==0) return 0;
    return pow(2,d-1);
}
void dfs(int node,int p,vector<vector<int>>&a)
{
    per[node]=p;
    up[node][0]=p;
    for(int j=1;j<L;j++)
    {
        if(up[node][j-1]!=-1) up[node][j]=up[up[node][j-1]][j-1];
    }
    for(auto &it:a[node])
    {
        if(it!=p)
        {
            depth[it]=depth[node]+1;
            dfs(it,node,a);
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int j=0;j<L;j++)
    {
        if(diff&(1<<j)) u=up[u][j];
    }
    if(u==v) return u;
    for(int j=L-1;j>=0;j--){
        if(up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}
int dist(int u,int v)
{
    int l=lca(u,v);
    int d=depth[u]+depth[v]-2*depth[l];
    return way(d);
}
    vector<int> assignEdgeWeights(vector<vector<int>>& e, vector<vector<int>>& q) {
        int n=e.size()+2;
        vector<vector<int>>a(n);
        for(auto &it:e)
        {
            int u=it[0],v=it[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        per.resize(n,-1);
        depth.resize(n,0);
        up.resize(n,vector<int>(L,-1));
        dfs(1,-1,a);
        vector<int>ans;
        for(auto &it:q)
        {
            int u=it[0],v=it[1];
            ans.push_back(dist(u,v));
        }
        return ans;
    }
};