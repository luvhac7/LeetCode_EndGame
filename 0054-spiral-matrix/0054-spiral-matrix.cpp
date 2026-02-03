class Solution {
public:
vector<int>res;
    vector<int> spiralOrder(vector<vector<int>>& a) {
    int r=a.size(),c=a[0].size(),x=0,y=0,dx=1,dy=0;
    for(int i=0;i<r*c;i++)
    {
        res.push_back(a[y][x]);
        a[y][x]=-101;
    if(!(0<=x+dx && x+dx<c && 0<=y+dy && y+dy<r)|| a[y+dy][x+dx]==-101)
    {
        int temp=dx;
        dx=-dy;
        dy=temp;
    }
    x+=dx;y+=dy;
    }
    return res;
    }
};