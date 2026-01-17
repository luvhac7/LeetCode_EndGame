class Solution {
public:
typedef long long ll;
ll x=0;
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        for(int i=0;i<b.size();i++){for(int j=i+1;j<b.size();j++){
            int x1=max(b[i][0],b[j][0]),
            y1=max(b[i][1],b[j][1]),
            x2=min(t[i][0],t[j][0]),
            y2=min(t[i][1],t[j][1]);
            ll w=x2-x1,h=y2-y1;
            if(w>0&&h>0){
                ll mini=min(w,h);
                x=max(x,mini);
            }
        }}
        return pow(x,2);
    }
};