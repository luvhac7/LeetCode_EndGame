class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ls=0;
        int cnt=0;
        int ans=accumulate(nums.begin(),nums.end(),0);
        for(int i:nums)
        {
            int rs=ans-ls-i;
            if(i==0)
            {
                if(ls==rs)
                {
                cnt+=2;
            }
            else if(ls==rs-1 || rs==ls-1)
            {
                cnt++;
            }
        }
        ls+=i;
    }
    return cnt;
}

};