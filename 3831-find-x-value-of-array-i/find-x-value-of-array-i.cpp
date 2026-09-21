class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(k,0));
        dp[0][nums[0]%k]++;
       unordered_map<int,long long>premp;
        premp[nums[0]%k]++;
        for(int i=1;i<n;i++){
            unordered_map<int,long long>curmp;
            curmp[nums[i]%k]++;
            for(auto it:premp){
                long long mod=it.first;
                int ct=it.second;
                mod=(mod*nums[i])%k;
                curmp[mod]+=ct;
            }
            for(auto it:curmp){
                int mod=it.first;
                int ct=it.second;
                dp[i][mod]+=ct;
            }
            premp=curmp;
        }
        vector<long long>ans(k,0);
        for(int i=0;i<k;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=dp[j][i];
            }
            ans[i]=sum;
        }
        return ans;
    }
};