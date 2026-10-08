class Solution {
public:
    string removeOuterParentheses(string& s) {
        int b=0, j=0;
        for(char c: s){
            b+=1-((c-'(')<<1);
            s[j]=c;
            j+=!(b+c-'('==1);
        }
        s.resize(j);
        return s;
    }
};