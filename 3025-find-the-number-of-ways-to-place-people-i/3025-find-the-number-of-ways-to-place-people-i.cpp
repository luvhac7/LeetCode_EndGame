class Solution {
public:


    int numberOfPairs(vector<vector<int>>& p) {
        int n=p.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
int ax=p[i][0],ay=p[i][1];
int bx=p[j][0],by=p[j][1];
if(ax>bx||ay<by)
{
    continue;
}
bool ok=true;
int minx=min(ax,bx);
int maxx=max(ax,bx);
int miny=min(ay,by);
int maxy=max(ay,by);
for(int k=0;k<n;k++)
{
    if(k==i||k==j) continue;
    int cx=p[k][0],cy=p[k][1];
    if(cx>=minx && cx<=maxx && cy>=miny && cy<=maxy){
        ok=false;
        break;
    }
}
if(ok) ans++;
            }
        }
        return ans;
    }
};