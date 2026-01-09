class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        int i=0,j=0,start=-1,match=0;
        while(i<n)
        {
            if(j<m && (p[j]=='?'||p[j]==s[i]))
            {
                i++;
                j++;
            }
            else if(j<m && p[j]=='*')
            {
                start=j;
                match=i;
                j++;
            }
            else if(start!=-1)
            {
                j=start+1;
                match++;
                i=match;
            }
            else{
                return false;
            }
        }
        while(j<m && p[j]=='*')
        {
            j++;
        }
        return j==m;
    }
};