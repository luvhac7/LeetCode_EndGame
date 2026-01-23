class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxp=nums[0],mnp=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            int cur=nums[i];
            if(cur<0)
                swap(mxp,mnp);
            mxp=max(cur,cur*mxp);
            mnp=min(cur,cur*mnp);
            ans=max(mxp,ans);
        }
        return ans;
    }
};