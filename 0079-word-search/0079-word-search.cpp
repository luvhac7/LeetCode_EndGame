class Solution {
public:
int m,n;
vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
bool find(vector<vector<char>>&b,int i,int j,int idx,string &w)
{
    if(idx==w.size()) return true;
    if(i<0||j<0||i>=m||j>=n||b[i][j]=='$') return false;
if(b[i][j]!=w[idx]) return false;
    char temp=b[i][j];
    b[i][j]='$';
   // if(b[i][j]!=w[idx]) return false;
    for(auto &d:dir)
    {
        int ni=i+d[0];
        int nj=j+d[1];
        if(find(b,ni,nj,idx+1,w)) return true;
    }
    b[i][j]=temp;
    return false;
}
    bool exist(vector<vector<char>>& b, string w) {
     m=b.size(),n=b[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==w[0] && find(b,i,j,0,w))
            {
                return true;
            }
        }
    }
    return false;
    }

};