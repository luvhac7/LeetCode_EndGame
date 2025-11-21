class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
         int cmax=0,cmin=0,maxi=INT_MIN,mini=INT_MAX;
         int t=0;
         for(int i:nums)
         {
            t+=i;
            cmax=max(i,cmax+i);
            maxi=max(cmax,maxi);
            cmin=min(i,cmin+i);
            mini=min(cmin,mini);
         }
         return (maxi<0) ? maxi:max(maxi,t-mini); 
    }
};