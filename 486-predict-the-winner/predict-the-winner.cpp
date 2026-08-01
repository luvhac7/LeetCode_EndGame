class Solution {
public:
    int n;
    bool ans;
    int solve(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        int a=nums[i]-solve(i+1,j,nums);
        int b=nums[j]-solve(i,j-1,nums);      
        return max(a,b);
    }

    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        ans=false;
        return solve(0,n-1,nums)>=0;
    }
};