class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int fkc=0;
        for(int i=0;i<s.length();i++)
        {
            //bool vector ->128 and false
            vector<bool>vis(128,false);
            for(int j=i;j<s.length();j++)
            {
                if(vis[s[j]]) break;
                else{
                    fkc=max(fkc,j-i+1);
                    vis[s[j]]=true;
                }
            }

        }
        return fkc;
    }
};