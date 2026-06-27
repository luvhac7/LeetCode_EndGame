class Solution {
public:
bool pr(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
int rev(int n)
{
    int r=0;
    while(n>0)
    {
        int last=n%10;
        r=(r*10)+last;
        n/=10;
    }
    return r;
}
    int sumOfPrimesInRange(int n) {
       int r=rev(n);
        int mini=min(n,r);
        int maxi=max(n,r);
        int s=0;
        for(int i=mini;i<=maxi;i++)
        {
            if(pr(i)) s+=i;
        }
        return s;
    }
};