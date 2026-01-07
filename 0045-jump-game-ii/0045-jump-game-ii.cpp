class Solution {
public:
    int st=0,end=0;
    int jump(vector<int>& nums) {
        int n=nums.size();
       int cnt=0;
       int end=0;
       int k=0;
       for(int i=0;i<n-1;i++)
       {
        k=max(k,i+nums[i]);
        if(i==end){
            cnt++;
            end=k;
        }
       }
       return cnt;
    }
};