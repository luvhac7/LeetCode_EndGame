class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), MOD = 1e9 + 7;
        vector<vector<int>> dp_s(n, vector<int>(n, -1)),
            dp_p(n, vector<int>(n, 0));

        dp_s[n - 1][n - 1] = 0;
        dp_p[n - 1][n - 1] = 1;

        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1))
                    continue;

                int max_s = -1, paths = 0;
                int dirs[3][2] = {{r + 1, c}, {r, c + 1}, {r + 1, c + 1}};

                for (auto& d : dirs) {
                    int nr = d[0], nc = d[1];
                    if (nr < n && nc < n && dp_s[nr][nc] != -1) {
                        if (dp_s[nr][nc] > max_s) {
                            max_s = dp_s[nr][nc];
                            paths = dp_p[nr][nc];
                        } else if (dp_s[nr][nc] == max_s) {
                            paths = (paths + dp_p[nr][nc]) % MOD;
                        }
                    }
                }
                if (max_s != -1) {
                    dp_s[r][c] =
                        max_s + (board[r][c] == 'E' ? 0 : board[r][c] - '0');
                    dp_p[r][c] = paths;
                }
            }
        }
        return dp_s[0][0] == -1 ? vector<int>{0, 0}
                                : vector<int>{dp_s[0][0], dp_p[0][0]};
    }
};

