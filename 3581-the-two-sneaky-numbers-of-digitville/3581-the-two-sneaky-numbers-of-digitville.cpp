class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                if(cnt<2)
                {
                ans.push_back(nums[i-1]);
                cnt++;
                }
            }
        }
        return ans;
    }
};