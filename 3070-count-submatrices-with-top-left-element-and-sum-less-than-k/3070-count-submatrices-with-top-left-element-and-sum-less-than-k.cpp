class Solution {
public:
    int countSubmatrices(vector<vector<int>>&a, int k) {
        int m=a.size(),n=a[0].size();
        int x=0;
        vector<vector<int>>sum(m+1,vector<int>(n+1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
sum[i+1][j+1]=a[i][j]+sum[i][j+1]+sum[i+1][j]-sum[i][j];
if(sum[i+1][j+1]<=k)
{
    ++x;
}
            }
        }
        return x;
    }
};