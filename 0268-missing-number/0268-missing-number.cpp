class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int st=nums[0],ed=nums[n-1];
        if(st==1) return 0;
        for(int i=st;i<ed;i++){
            if(i!=nums[i]){
                return i;
            }
        }
        return ed+1;
    }
};