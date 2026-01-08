class Solution {
public:
typedef unsigned long long ll;
    int change(int n, vector<int>& c) {
        if (n == 0)
            return 1;

        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        for (int i : c) {
            if (i <= 0)
                continue;
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j-i];
            }
        }
        return (int)dp[n];
    }
};
