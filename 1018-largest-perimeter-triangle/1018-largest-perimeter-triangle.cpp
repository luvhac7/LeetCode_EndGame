typedef long long ll;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll temp=0;
        for(int i=nums.size()-1;i>=2;i--)
        {
            if(nums[i-1]+nums[i-2]>nums[i])
            {
                temp=nums[i-1]+nums[i]+nums[i-2];
                break;
            }
        }
        return (int)temp;
    }
};