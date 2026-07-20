class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        int m=a.size(),n=a[0].size();
        k=k%(m*n);
        for(int l=0;l<k;l++)
        {int idx=(m*n)-1;
            for(int p=1;p<m*n;p++)
            {
                int i=idx/n,j=idx%n;
                idx--;int k=idx/n,l=idx%n;
                swap(a[i][j],a[k][l]);
            }
        }
        return a;
    }
};