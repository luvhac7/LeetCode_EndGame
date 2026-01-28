class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            char x=t[i];
            for(int j=0;j<n;j++)
            {
        if(s[j]==c && t[j]!=x) return false;
        if(s[j]!=c && t[j]==x) return false;
            }
        }
        return true;
    }
};