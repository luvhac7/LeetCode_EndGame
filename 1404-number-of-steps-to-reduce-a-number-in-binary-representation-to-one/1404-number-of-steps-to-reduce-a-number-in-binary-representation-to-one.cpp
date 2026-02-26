class Solution {
public:
    int numSteps(string s) {
        int sv=0,c=0;
        int n=s.size();
        for(int i=n-1;i>0;i--)
        {
            int b=s[i]&1;
            sv+=1+(b^c);
            c|=b;
        }
        return sv+c;
    }
};