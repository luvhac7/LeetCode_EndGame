class Solution {
public:
    vector<vector<int>> dp;
    int find(vector<int>& v, int i, int b) {
        int n = v.size();
        if (i == n)
            return 0;
        if (dp[i][b] != -1)
            return dp[i][b];
        int ans = INT_MIN;
        if (!b)
            ans = INT_MAX;
        int sum = 0;
        for (int k = i; k < min(n, i + 3); k++) {
            sum += v[k];

            if (b) {
                ans = max(ans, sum + find(v, k + 1, !b));
            }

            else {

                ans = min(ans, find(v, k + 1, !b));
            }
        }

        return dp[i][b] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        double sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        dp.resize(n + 1, vector<int>(3, -1));

        int k1 = find(stoneValue, 0, 1);
        //  dp.assign(n+1,vector<int>(2,-1));
        //  int k2=find2(stoneValue,0,1);
        cout << k1;
        double half = double(sum / 2);
        if (k1 == half) {
            return "Tie";
        }

        if (k1 > half) {
            return "Alice";
        }

        return "Bob";
    }
};