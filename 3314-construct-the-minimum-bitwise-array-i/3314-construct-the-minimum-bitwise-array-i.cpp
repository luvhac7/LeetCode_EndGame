class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        for(auto &i:nums)
        {
            if(i&1)
            {
                int z=((i+1)&~i)>>1;
                res.push_back(~z & i);
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};