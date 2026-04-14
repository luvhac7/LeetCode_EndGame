class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n = robot.size(), m = factory.size();

        robot.insert(robot.begin(), 0);
        factory.insert(factory.begin(), {0, 0});

        vector<vector<long long>> f = vector(200, vector<long long>(200, 1e18 + 7));

        for (int i = 0; i <= m; i++) {
            f[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int pos = factory[j][0], limit = factory[j][1];

                for (int k = 0; k <= min(i, limit); k++) {
                    long long mark1 = 0;
                    
                    for (int l = i - k + 1; l <= i; l++) {
                        mark1 += abs(robot[l] - pos);
                        // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << mark1 << "\n";
                    }

                    f[i][j] = min(f[i][j], f[i - k][j - 1] + mark1);
                    // cout << i << ' ' << j << ' ' << k << ' ' << i - k << ' ' << j - 1 << "\n" << f[i][j] << ' ' << f[i - k][j - 1] << ' ' << mark1 << "\n\n";
                }
            }
        }
        
        return f[n][m];
    }
};