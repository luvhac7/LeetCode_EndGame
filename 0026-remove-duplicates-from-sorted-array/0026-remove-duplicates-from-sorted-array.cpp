class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>ans;
        for(int i:nums) ans.insert(i);

        int k=0;
        for(int i:ans){
            nums[k++]=i;
        }
        return k;
    }
};