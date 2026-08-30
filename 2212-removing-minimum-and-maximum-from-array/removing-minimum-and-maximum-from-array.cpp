class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=max_element(nums.begin(),nums.end())-nums.begin();
        int mn=min_element(nums.begin(),nums.end())-nums.begin();
        int n=nums.size();
        int left=min(mx,mn);
        int right=max(mx,mn);
        int case1=n-left;
        int case2=right+1;
        int case3=left+1+n-right;
        return min({case1,case2,case3});
    }
};