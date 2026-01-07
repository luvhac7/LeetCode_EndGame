class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n,1);
        int pre=1;
        for(int i=0;i<n;i++)
        {
            ans[i]=pre;
            pre*=a[i];
        }
        int suf=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]*=suf;
            suf*=a[i];
        }
        return ans;
    }
};