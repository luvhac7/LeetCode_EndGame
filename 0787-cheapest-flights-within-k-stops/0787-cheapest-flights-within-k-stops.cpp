class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        //1
        vector<vector<pair<int,int>>>g(n);
        for(int i=0;i<f.size();i++)
        {
            int u=f[i][0];
            int v=f[i][1];
            int w=f[i][2];
            g[u].push_back({v,w});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        //2
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{src,k+1}});
        //3
        while(!pq.empty())
        {
            int cost=pq.top().first;
            int u=pq.top().second.first;
            int stop=pq.top().second.second;
            pq.pop();
            if(u==dst)
            {
                return cost;
            }
            if(stop==0)continue;
            if(cost>dist[u][stop])continue;
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i].first;
                int w=g[u][i].second;
                if(cost+w<dist[v][stop-1]){
                    dist[v][stop-1]=cost+w;
                    pq.push({cost+w,{v,stop-1}});
                }
            }
        }
        return -1;

    }
};