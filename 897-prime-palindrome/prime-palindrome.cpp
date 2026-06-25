class Solution {
public:
bool p(int n)
{
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
bool p2(int n)
{
    int o=n;
    int r=0;
    while(n)
    {
        r=r*10+n%10;
        n/=10;
    }
    return o==r;
}
    int primePalindrome(int n) {
        // if(!p(n)) return n+1;
        // else return n;
        while(1)
        {
            if(p(n) && p2(n)) return n;
            if(n>=1e7 && n<=1e8-1){ n=1e8; continue;}
            n++;
        }
    }
};