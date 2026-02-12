class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int f[26]={0};
            for(int j=i;j<n;j++)
            {
                int cur=++f[s[j]-'a'];
                if(maxi>=j-i+1)
                {
                    continue;
                }
                bool ok=true;
                for(int k=0;k<26;k++)
                {
                    if(f[k]&&f[k]!=cur)
                    {
                        ok=false;break;
                    }
                }
                if(ok) maxi=max(maxi,j-i+1);
            }

        }
        return maxi;
    }
};