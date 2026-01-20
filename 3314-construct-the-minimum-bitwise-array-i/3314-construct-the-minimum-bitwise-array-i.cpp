class Solution {
public:
vector<int>r;
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i:nums)
        {
            if(i & 1)
            {
                int x=((i+1)&~i)>>1;
                r.push_back(~x&i);
            }
            else{
                r.push_back(-1);
            }
        }
        return r;
    }
};