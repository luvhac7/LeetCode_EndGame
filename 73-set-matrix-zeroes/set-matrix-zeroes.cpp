class Solution {
public:
    void setZeroes(vector<vector<int>>&a) {
int n=a.size(),m=a[0].size();
vector<bool>row(n,false),col(m,false);
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(a[i][j]==0)
        {
            row[i]=true;
            col[j]=true;
        }
    }
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(row[i]||col[j])
        {
        a[i][j]=0;
        }

    }
}
    }
};