class Solution {
public:
typedef long long ll;
    int minCost(int n, vector<vector<int>>& a) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &i:a)
        {
            int u=i[0],v=i[1],w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        ll INF=1e18;
        vector<ll>dist(n,INF);
        using T=pair<ll,int>;
        priority_queue<T,vector<T>,greater<T>>pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto [cost,u]=pq.top();
            pq.pop();
            if(cost!=dist[u]) continue;
            for(auto &[v,w]:adj[u]){
                ll nc=cost+w;
                if(nc<dist[v]){
                    dist[v]=nc;
                    pq.push({nc,v});
                }
            }
        }
        return dist[n-1]==INF ? -1:dist[n-1];
    }
};