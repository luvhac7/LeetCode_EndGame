class Solution {
public:
    bool check(int i, int j, string &s, vector<vector<int>> &p) {
        if (p[i][j] != -1) {
            return p[i][j];
        }
        while (i < j) {
            if (s[i] != s[j]) {p[i][j] = 0;return false;
            }
            i++;
            j--;
        }
        p[i][j] = 1;
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k==1)return n;
        vector<int> dp(n + 1, 0);
        vector<vector<int>> a(n, vector<int>(n, -1));
        for (int ind = n - 1; ind >= 0; ind--) {
            int ntake=dp[ind+1];
            int take=0;
            for (int i = ind; i < n; i++) {
                if ((i - ind + 1) >= k && check(ind, i, s, a)) {
                   take = max(take, 1 + dp[i + 1]);
                }
            }
            dp[ind] = max(take, ntake);
        }
        return dp[0];
    }
};