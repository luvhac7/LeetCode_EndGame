class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            int a[26]={0};
            int dc=0,maxi=0;
            for(int j=i;j<n;j++)
            {
                int idx=s[j]-'a';
                if(a[idx]==0) dc++;
                a[idx]++;
                maxi=max(maxi,a[idx]);
                if(j-i+1==dc*maxi)
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};