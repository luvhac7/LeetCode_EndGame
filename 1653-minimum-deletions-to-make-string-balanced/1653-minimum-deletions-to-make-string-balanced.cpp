class Solution {
public:
    int minimumDeletions(string s) {
        int x=0,b=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='b') b++;
            else{
                if(b>0)
                {
                    b--;x++;
                }
            }
        }
        return x;
    }
};