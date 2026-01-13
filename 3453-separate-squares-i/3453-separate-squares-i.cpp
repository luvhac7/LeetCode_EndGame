class Solution {
public:
typedef double d;
d below(vector<vector<int>>&sq,d y)
{
    d t=0;
    for(auto &s:sq)
    {
        d blw=s[1];
        d len=s[2];
        if(y>blw){
            t+=min(y-blw,len)*len;
        }
    }
    return t;
}
d area(vector<vector<int>>sq)
{
    d t=0;
    for(auto &s:sq){
        t+=(d)s[2]*s[2];
    }
    return t;
}

    double separateSquares(vector<vector<int>>& sq) {
        d l=1e18,h=-1e18;
        for(auto &s:sq)
        {
            l=min(l,(d)s[1]);
            h=max(h,(d)s[1]+s[2]);
        }
        d t=area(sq);
        for(int i=0;i<80;i++)
        {
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