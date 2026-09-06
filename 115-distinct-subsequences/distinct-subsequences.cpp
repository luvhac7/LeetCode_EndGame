class Solution {
public:

    int f(vector<vector<int>>& dp, string s, string t, int i, int j){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = f(dp, s,t, i+1, j) + f(dp, s, t, i+1, j+1);
        return dp[i][j] = f(dp, s, t, i+1, j);
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(dp, s, t, 0, 0);
    }
};