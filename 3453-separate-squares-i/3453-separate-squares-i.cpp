class Solution {
public:
typedef double d;
    d area(vector<vector<int>>&sq)
    {
        d t=0;
        for(auto &s:sq)
        {
            t+=1.0*s[2]*s[2];
        }
        return t;
    }
    d below(vector<vector<int>>&sq,d y)
    {
        d a=0.0;
        for(auto &s:sq)
        {
            d btm=s[1];
            d len=s[2];
            if(y>btm){
                a+=min(y-btm,len)*len;
            }
        }
        return a;
    }

    double separateSquares(vector<vector<int>>& sq) {
        d l=1e18,h=-1e18;
        for(auto &s:sq)
        {
            l=min(l,(d)s[1]);
            h=max(h,(d)s[1]+s[2]);
        }
        d t=area(sq);
        for(int i=0;i<80;i++){
            d mid=(l+h)/2;
            if(below(sq,mid)*2<t){
                l=mid;
            }
            else{
                h=mid;
            }
        }
        return l;
    }
};