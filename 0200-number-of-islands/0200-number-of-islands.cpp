class Solution {
public:
void dfs(int i,int j,vector<vector<char>>&a)
{
    int n=a.size(),m=a[0].size();
    if(i<0||j<0||i>=n||j>=m||a[i][j]=='0') return;
    a[i][j]='0';
    dfs(i-1,j,a);//up
    dfs(i+1,j,a);//down
    dfs(i,j-1,a);//left
    dfs(i,j+1,a);//right
}
    int numIslands(vector<vector<char>>& a) {
        int is=0;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                if(a[i][j]=='1')
                {
                    dfs(i,j,a);
                    is++;
                }
            }
        }
        return is;
    }
};
