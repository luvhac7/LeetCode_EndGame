class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int tar) {
     int s=0;
     for(int x:nums) s+=x;
     if(s+tar<0 ||(s+tar)%2!=0){
        return 0;
     }  
     int sum=(s+tar)/2;
     vector<int>dp(sum+1,0);
     dp[0]=1;
     for(int i:nums)
     {
        for(int j=sum;j>=i;j--)
        {
            dp[j]+=dp[j-i];
        }
     } 
     return dp[sum];
    }
};