class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x=0;
        for(int i=0;i<t.size();i++)
        {
            if(x<s.size()&& t[i]==s[x]) x++;
        }
        return x==s.size();
    }
};