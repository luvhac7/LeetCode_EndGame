class Solution {
public:
int dfs(vector<vector<int>>&a,int r,int c,int row,int col)
{
    if(r<0 || r>=row ||c<0 || c>=col || a[r][c]==0)
    {
        return 0;
    }
    a[r][c]=0;
    int area=1;
    area+=dfs(a,r+1,c,row,col);
    area+=dfs(a,r-1,c,row,col);
    area+=dfs(a,r,c+1,row,col);
    area+=dfs(a,r,c-1,row,col);
    return area;
}

vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int maxAreaOfIsland(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            
            if(a[i][j]==1)
            {
                maxi=max(maxi,dfs(a,i,j,n,m));
            }
            }
        }
        return maxi;
    }
};