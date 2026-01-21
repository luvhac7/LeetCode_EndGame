class Solution {
public:
vector<int>res;
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i:nums){
            if(i!=2) res.push_back(i-((i+1)&(-i-1))/2);
        
        else res.push_back(-1);
        }
        return res;
    }
};