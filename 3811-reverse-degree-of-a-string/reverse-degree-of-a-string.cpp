class Solution {
public:
    int reverseDegree(string s) {
        int x=0,n=s.size();
        for(int i=0;i<n;i++) x+=(i+1)*('z'-s[i]+1);
        return x;
    }
};