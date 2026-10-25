class Solution {
public:
    void dfs(int row,int col, vector<vector<int>> &vis, vector<vector<int>>& grid,int n,int m){
        vis[row][col]=1;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                dfs(nrow,ncol,vis,grid,n,m);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && grid[0][j]==0){
                    dfs(0,j,vis,grid,n,m);
            }
            if(vis[n-1][j]==0 && grid[n-1][j]==0){
                    dfs(n-1,j,vis,grid,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && grid[i][0]==0){
                    dfs(i,0,vis,grid,n,m);
            }
            if(vis[i][m-1]==0 && grid[i][m-1]==0){
                    dfs(i,m-1,vis,grid,n,m);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==0){
                    ans++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return ans;
    }
};