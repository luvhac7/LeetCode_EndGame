class Solution {
public:
typedef long long ll;
bool solve(vector<int>&a,int m,int k)
{
    ll ts=0;
    for(int  i=0;i<a.size();i++)
    {
        ts+=(a[i]+m-1)/m;
    }
    return ts<=k;

}
int bs(vector<int>&a,int k)
{
    int l=1,h=*max_element(a.begin(),a.end());
    int res=h;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(solve(a,m,k))

        {
            res=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return res;
}
    int minEatingSpeed(vector<int>& a, int h) {
        return bs(a,h);
    }
};