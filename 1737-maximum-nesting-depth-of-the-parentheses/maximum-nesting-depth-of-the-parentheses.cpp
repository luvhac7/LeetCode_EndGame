class Solution {
public:
    int maxDepth(string s) {
        int max=0;
        int len =0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            len++;
            else if(s[i]==')')
            len--;
            if(len>max)
            max=len;
        }
        return max;
    }
};