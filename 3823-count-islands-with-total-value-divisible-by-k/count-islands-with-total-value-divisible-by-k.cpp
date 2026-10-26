class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>>& grid) {
        if(i>=grid.size() || j>=grid[0].size()) {
            return 0;
        }
        long long islandSum = (long long)grid[i][j];
        grid[i][j] = 0;
        vector<int> dr = {0,1,-1,0};
        vector<int> dc = {1,0,0,-1};
        for(int k = 0; k < 4; k++) {
            int nr = dr[k]+i;
            int nc = dc[k]+j;
            if(nr>=0&&nc>=0&&nc<grid[0].size()&&nr<grid.size()&&grid[nr][nc]!=0){
                islandSum += dfs(nr, nc, grid);
            }
        }
        return islandSum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]>0) {
                    long long islandSum = dfs(i, j, grid);
                    if(islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};