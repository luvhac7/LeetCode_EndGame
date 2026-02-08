class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<int>res;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<int>dr={0,1,0,-1};
        vector<int>dc={1,0,-1,0};
        int r=0,c=0,idx=0;
        for(int i=0;i<m*n;i++)
        {
            res.push_back(a[r][c]);
            vis[r][c]=true;
            int newr=r+dr[idx];
            int newc=c+dc[idx];
        if(0<=newr && newr<m && 0<=newc && newc<n && !vis[newr][newc] )
        {
            r=newr;c=newc;
        }
        else{
            idx=(idx+1)%4;
            r+=dr[idx];
            c+=dc[idx];
        }
        }
        return res;
    }
};