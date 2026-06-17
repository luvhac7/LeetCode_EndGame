class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(),x=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ') x++;
            else if(x!=0) break;
        }
        return x;
    }
};