class Solution {
public:
int x=0;
    int singleNumber(vector<int>& nums) {
        for(int i:nums)
        {
            x^=i;
        }
        return x;
    }
};