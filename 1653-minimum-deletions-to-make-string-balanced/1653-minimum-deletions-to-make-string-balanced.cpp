class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size(),b=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b') b++;
            else{
                if(b>0){
                    b--;ans++;
                }
            }
        }
        return ans;
    }
};