class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>x(m,string(n,'#'));
        for(int i=0;i<n;i++) x[0][i]='.';
        for(int i=0;i<m;i++) x[i][n-1]='.';
        return x;
    }
};