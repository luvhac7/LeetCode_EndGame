class Solution {
public:
    int stoneGameV(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i =1;i <n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int length =2 ; length <=n;length++){
            for(int i =0;i<n-length+1;i++){
                int j = length + i -1;
                for(int k = i;k<j;k++){
                    int left = 0;
                    if(i == 0){
                        left = prefix[k];
                    }else
                    left = prefix[k] - prefix[i-1];

                    int right = prefix[j] - prefix[k];
                    int score = 0;
                    if (left < right){
                        score = (left + dp[i][k]);
                    }else if(right < left){
                        score = (right + dp[k+1][j]);
                    }
                    else {
                        score = left + max(dp[i][k], dp[k+1][j]);

                    }
                    dp[i][j] = max(dp[i][j] , score);
                }
            }
        }
        return dp[0][n-1];
    }
};