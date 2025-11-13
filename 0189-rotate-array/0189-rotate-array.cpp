class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l=nums.size();
        int t=l-k%l;
        vector<int>ans;
        for(int i=t;i<nums.size();i++)
        {
            ans.push_back(nums[i]);
            //cout<<nums[i]<<" ";
        }
        for(int i=0;i<t;i++)
        {
            //cout<<nums[i]<<" ";
            ans.push_back(nums[i]); 
        }
        nums=ans;

    }
};