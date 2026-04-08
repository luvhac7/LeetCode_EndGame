class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& a) {
        const int M=1e9+7;
        for(const auto &i:a)
        {
            int l=i[0],r=i[1],k=i[2],v=i[3];
    for(int idx=l;idx<=r;idx+=k)
    {
        nums[idx]=1LL*nums[idx]*v%M;
    }
        }
    int ans=0;
    for(int i:nums)
    {
        ans^=i;
    }
    return ans;
    }
};