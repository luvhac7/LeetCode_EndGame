class Solution {
public:
    int numSteps(string s) {
        int st=0,car=0;
        int n=s.size();
        for(int i=n-1;i>0;i--)
        {
            int b=s[i]&1;
            st+=1+(b^car);
            car|=b;
        }
        return st+car;
    }
};