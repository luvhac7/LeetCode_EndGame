class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ones=count(nums.begin(),nums.end(),1);
        int n=nums.size();
        if(ones>0){
            return n-ones;
        }
        int best=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int g=nums[i];
            for(int j=i;j<n;j++)
            {
                g=gcd(g,nums[j]);
                if(g==1)
                {
                    best=min(best,j-i+1);
                    break;
                }
            } 
        }
        return best ==INT_MAX ? -1 : (best-1)+(n-1); 
    }
};