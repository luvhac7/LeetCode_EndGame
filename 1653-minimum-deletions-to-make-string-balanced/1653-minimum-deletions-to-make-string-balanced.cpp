class Solution {
public:
    int minimumDeletions(string s) {
        int x=0,b=0;
        for(char i:s)
        {
            if(i=='b') b++;
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