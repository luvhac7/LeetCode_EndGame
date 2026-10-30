class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        map<pair<int,int>,int>dis;
        map<pair<int,int>,int>vis;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,1}});
        dis[{0,1}]=0;
        int maxi=INT_MAX;
        while(!pq.empty()){
            pair<int,pair<int,int>> cur=pq.top();
            pq.pop();
            if(vis[cur.second])continue;
            vis[cur.second]=1;
            int w=cur.first;
            int node=cur.second.first;
            int cons=cur.second.second;
            if(node==n-1)maxi=min(maxi,w);
            for(auto ad:adj[node]){
               int ne=ad.first;
               int ww=ad.second;
               int ncons=0;
               if(labels[ne]==labels[node])ncons=cons+1;
               else ncons=1;
               if(ncons>k)continue;
               if(!dis.count({ne,ncons})||w+ww<dis[{ne,ncons}]){
                  dis[{ne,ncons}]=w+ww;
                   pq.push({w+ww,{ne,ncons}});
               }

            }
        }
        if(maxi==INT_MAX)return -1;
        return maxi;
    }
};