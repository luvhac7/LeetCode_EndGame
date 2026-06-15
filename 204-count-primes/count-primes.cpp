class Solution {
public:
    int countPrimes(int n) {
        vector<bool>ans(n,true);
        if(n<=2) return false;
        ans[0]=ans[1]=false;
        for(int i=2;i*i<n;i++)
        {
            for(int j=i*i;j<n;j+=i)
            {
            ans[j]=false;
            }
        }   
        return count(ans.begin(),ans.end(),true);
    }
};