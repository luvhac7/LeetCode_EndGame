class Solution {
public:
typedef long long ll;
//a->bloomday ,d->day,m->bout,k->flower adj
bool ok(vector<int>&a,int d,int m,int k)
{
    int cnt=0,b=0;
    for(int i:a)
    {
        if(i<=d){
            cnt++;
            if(cnt==k)
            {
                b++;
                cnt=0;
            }
        }
        else{
            cnt=0;
        }
    }
    return b>=m;
}
int mini(vector<int>&a,int m,int k)
{
    ll t=1LL*m*k;
    if(t>a.size()) return -1;
    int l=*min_element(a.begin(),a.end());
    int h=*max_element(a.begin(),a.end());
    int res=-1;
    while(l<=h)
    {
        int d=l+(h-l)/2;
        if(ok(a,d,m,k))
        {
            res=d;
            h=d-1;
        }
        else{
            l=d+1;
        }
    }
    return res;
}
    int minDays(vector<int>& a, int m, int k) {
        return mini(a,m,k);
    }
};