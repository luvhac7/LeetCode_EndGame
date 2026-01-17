class Solution {
public:
typedef long long ll;
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
ll ans=abs(ax1-ax2)*abs(ay1-ay2)+abs(bx1-bx2)*abs(by1-by2);
int x=0,y=0;
for(int i=ax1;i<=ax2;i++)
{
    if(i<=bx2&& i>=bx1)
    {
        x++;
    }
}
for(int i=ay1;i<=ay2;i++)
{
    if(i>=by1 && i<=by2)
    {
        y++;
    }
}
if(x>0 && y>0)
{
    ans-=(x-1)*(y-1);
}
return ans;
    }
};