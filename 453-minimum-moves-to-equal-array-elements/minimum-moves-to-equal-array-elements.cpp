class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int fe=nums[0];
        int res=0;
        for(int i=1;i<n;i++)
        {
            res+=(nums[i]-fe);
        }
        return res;
    }
};