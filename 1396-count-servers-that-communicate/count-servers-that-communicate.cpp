class Solution {
public:
  int n,m;
  vector<vector<int>>vis;
  vector<vector<int>>grid;
  int dfs(int x, int y){
           vis[x][y]=1;
           int ans= 1;
           for(int i=0;i<m;i++){
              if(grid[x][i]==1 && !vis[x][i]){
                  ans += (dfs(x,i));
              }
           }
           for(int i=0;i<n;i++){
              if(grid[i][y]==1 && !vis[i][y]){
                  ans += (dfs(i,y));
              }
           }
           return ans;
  }
    int countServers(vector<vector<int>>& grid) {
          n = grid.size();
          m = grid[0].size();
          this->grid = grid;
         vis.resize(n,vector<int>(m,0));
         vector<int>ans;
         for(int  i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(grid[i][j]==1 && vis[i][j]==0){
                         int val = dfs(i,j);
                         ans.push_back(val);
                  }
              }
         }
         int res = 0;
         for(int i=0;i<ans.size();i++){
              if(ans[i]>1){
                res+=ans[i];
              }
         }
         return res;
    }
};