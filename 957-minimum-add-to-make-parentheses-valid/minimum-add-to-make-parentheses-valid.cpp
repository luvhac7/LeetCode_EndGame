class Solution {
public:
    int minAddToMakeValid(string s) {
        int p1=0,p2=0;
        for(char c:s){
            if(c=='(') p1++;
            else{
                if(p1>0) p1--;
                else{
                    p2++;
                }
            }
        }
        return p1+p2;
    }
};