class Solution {
public:
    int minAddToMakeValid(string s) {
        int x=0,y=0;
        for(char c:s)
        {
            if(c=='(') x++;
            else
            {
                if(x>0)x--;
                else{
                    y++;
                }
            }
        }
        return x+y;
    }
};