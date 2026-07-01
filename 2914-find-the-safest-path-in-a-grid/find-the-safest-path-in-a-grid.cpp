class Solution {
    const vector<vector<int>> dirs = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    int n;

    bool canVisit(int i, int j) {
        if (i<0 || j<0 || i>=n || j>=n)
            return false;
        return true;
    }

    void calculateSafeness(vector<vector<int>> &safeness, const vector<vector<int>>& grid) {
        queue<pair<int,int>> bfs;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    bfs.push({i,j});
                    safeness[i][j]=0;
                }
            }
        }

        int layer, depth=0, i, j, ni, nj;

        while (!bfs.empty()) {
            layer=bfs.size();
            depth++;
            while (layer--) {
                i=bfs.front().first;
                j=bfs.front().second;
                bfs.pop();

                for (vector<int> dir : dirs) {
                    ni=i+dir[0];
                    nj=j+dir[1];
                    if (canVisit(ni, nj) && safeness[ni][nj]==-1) {
                        bfs.push({ni,nj});
                        safeness[ni][nj]=depth;
                    }
                }
            }
        }
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> safeness(n, vector<int>(n, -1));

        calculateSafeness(safeness, grid);

        vector<vector<int>> parent(n, vector<int>(n, -2));
        priority_queue<pair<int,pair<int,int>>> pq;

        parent[0][0]=-1;
        pq.push({safeness[0][0], {0,0}});
        int i, j, ni, nj;

        while (parent[n-1][n-1]==-2) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();

            for (int d=0; d<4; d++) {
                ni=i+dirs[d][0];
                nj=j+dirs[d][1];

                if (canVisit(ni, nj) && parent[ni][nj]==-2) {
                    parent[ni][nj]=d;
                    pq.push({safeness[ni][nj], {ni,nj}});
                }
            }
        }

        i=n-1;
        j=n-1;
        int res=safeness[i][j], d;
        while (parent[i][j]>=0) {
            d=parent[i][j];
            i-=dirs[d][0];
            j-=dirs[d][1];
            res=min(res, safeness[i][j]);
        }
        return res;
    }
};