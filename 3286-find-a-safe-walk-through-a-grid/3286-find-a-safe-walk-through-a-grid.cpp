class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& a, int h) {
        int m=a.size(),n=a[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,less<>>pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({h,0,0});
        while(!pq.empty())
        {
            auto [cur,x,y]=pq.top();pq.pop();
            cur-=a[x][y];
            if(cur<1) continue;
            if(x==m-1 && y==n-1) return true;
            if(vis[x][y]) continue;
            vis[x][y]=true;
            for(int i=0;i<4;i++)
            {
                int dx=x+dir[i][0],dy=y+dir[i][1];
                if(dx>=0 && dx<m && dy>=0 && dy<n && !vis[dx][dy])
                {
                    pq.push({cur,dx,dy});
                }
            }
        }
        return false;
    }
};