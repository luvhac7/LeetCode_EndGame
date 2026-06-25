class Solution {
public:
typedef vector<int> vi;
bool inc(vi & a)
{
    for(int i=1;i<a.size();i++) if(a[i-1]>=a[i]) return false;
    return true;
}
bool is(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
    bool primeSubOperation(vector<int>& a) {
        if(inc(a)) return true;int n=a.size();
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]>=a[i+1])
            {
                int dif=a[i]-a[i+1];
                int p=dif+1;
                while(!is(p))
                {
                    p++;
                }
                if(a[i]-p<=0) return false;
                a[i]-=p;
            }
        }
        return true;
    }
};