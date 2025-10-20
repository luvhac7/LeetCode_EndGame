class Solution {
public:
    void dfs(vector<vector<char>>&v,int r,int c)
    {
        int R=v.size();
        int C=v[0].size();
        if(r<0 || c<0|| r>=R || c>=C ||v[r][c]=='0')
        {
            return;
        }
        v[r][c]='0';
        dfs(v,r+1,c);
        dfs(v,r-1,c);
        dfs(v,r,c+1);
        dfs(v,r,c-1);
    }
    int numIslands(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int min_zero=0;
       if(mat.empty() || mat[0].empty()){
        return 0;
       }
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]=='1')
            {
                min_zero++;
                dfs(mat,i,j);
            } 
        }
       }
       return min_zero;
    }
};