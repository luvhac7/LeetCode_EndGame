class Solution {
public:
    int binaryGap(int n) {
        bitset<32>b(n);
        string s=b.to_string();
        int ans=0,last=-1;
        for(int i=0;i<32;i++)
        {
            if((n>>i)&1)
            {
                if(last!=-1)
                {
                    ans=max(ans,i-last);
                }
                last=i;
            }
        }
        return ans;
    }
};