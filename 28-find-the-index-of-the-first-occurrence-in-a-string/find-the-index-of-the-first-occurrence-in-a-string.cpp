class Solution {
public:
    int strStr(string x, string y) {
    //     string ans="";
    //     for(int i=0;i<x.size();i++)
    //     {
    //         for(int j=0;j<y.size();j+=i)
    //         {
    //             if(x[i]==y[j]) ans+=x[i];
    //             else ans="";
    //         }
    //     }
    // cout<<ans<<""
    //     return ans.size();
    int n=x.size(),m=y.size();
    if(m==0) return 0;
    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        while(j<m && x[i+j]==y[j]) j++;
        if(j==m) return i;
    }
    return -1;
    }
};