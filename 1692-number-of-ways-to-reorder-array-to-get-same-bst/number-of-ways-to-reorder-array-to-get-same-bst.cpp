class Solution {
public:
    vector<vector<long long>> dp;
    int MOD = 1e9 + 7;
    long long nCr(int n, int r) {
        if(r == 0 || r == n)
            return 1;

        if(dp[n][r] != -1)
            return dp[n][r];

        return dp[n][r] = (nCr(n - 1, r - 1)%MOD + nCr(n - 1, r)%MOD)%MOD;
    }
    int solve(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==0) return 0;
        vector<int> left, right;
        int first = nums[0];
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<first) {
                left.push_back(nums[i]);
            }
            if(nums[i]>first) {
                right.push_back(nums[i]);
            }
        }
        int le=1, ri=1;
        if(left.size()>0) le = solve(left);
        if(right.size()>0) ri = solve(right);
        long long res = ( nCr(n-1, right.size()))%MOD;
        res = (res * le)%MOD;
        res = (res * ri)%MOD;
        return res;

    }
    int numOfWays(vector<int>& nums) {
        dp.assign(1001, vector<long long>(1001, -1));
        return solve(nums) - 1;
    }
};