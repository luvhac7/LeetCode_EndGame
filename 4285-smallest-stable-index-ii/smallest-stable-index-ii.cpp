class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int max=INT_MIN,min=INT_MAX;
        vector<int> m1;
        vector<int> m2;
        for(int i=0,j=nums.size()-1;i<nums.size()&&j>=0;i++,j--){
            if(max<nums[i]){
                max=nums[i];
            }
            if(min>nums[j]){
                min=nums[j];
            }
            m1.push_back(max);
            m2.push_back(min);
        }
        reverse(m2.begin(),m2.end());
        for(int i=0;i<nums.size();i++){
            if(m1[i]-m2[i]<=k){
                return i;
            }
        }
        return -1;
    }
};