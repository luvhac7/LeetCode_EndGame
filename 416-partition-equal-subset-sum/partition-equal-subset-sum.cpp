class Solution {
public:
    bool canPartition(vector<int>&a) {
        int sum=accumulate(a.begin(),a.end(),0);
        if(sum%2!=0) return false;
        int tar=sum/2;
        vector<bool>dp(tar+1,false);
        dp[0]=true;
        for(int i:a)
        {
            for(int j=tar;j>=i;j--)
            {
                if(dp[j-i])
                {
                    dp[j]=true;
                }
            }
        }
        return dp[tar];  
    }
};