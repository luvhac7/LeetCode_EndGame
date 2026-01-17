class Solution {
public:
typedef long long ll;
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        ll maxi=0,s=0;
  for(int i=0;i<bl.size();i++)
  {
    for(int j=i+1;j<bl.size();j++)
    {
        int x1=max(bl[i][0],bl[j][0]);
        int y1=max(bl[i][1],bl[j][1]);
        int x2=min(tr[i][0],tr[j][0]);
        int y2=min(tr[i][1],tr[j][1]);

        ll w=x2-x1;
        ll h=y2-y1;
if(w>0&&h>0){
        ll ans=min(w,h);
        maxi=max(ans,maxi);
    }
    }
  }      
  return maxi*maxi;
    }
};