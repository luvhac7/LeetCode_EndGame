class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 1000000007;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(2, -1))
        );

        function<int(int,int,bool)> solve = [&](int i, int j, bool right) {
            if(i >= n || j >= m) return 0;

            if(i == n-1 && j == m-1) return 1;

            if(dp[i][j][right] != -1)
                return dp[i][j][right];

            if(grid[i][j] == 1) {
                if(right) {
                    return dp[i][j][right] = solve(i+1, j, false);
                }
                else {
                    return dp[i][j][right] = solve(i, j+1, true);
                }
            }

            long long ans = 0;

            ans += solve(i, j+1, true);
            ans += solve(i+1, j, false);

            return dp[i][j][right] = ans % MOD;
        };

        return solve(0, 0, true);
    }
};