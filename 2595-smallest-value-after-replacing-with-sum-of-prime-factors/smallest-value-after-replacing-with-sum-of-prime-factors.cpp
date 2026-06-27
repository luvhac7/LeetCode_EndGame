class Solution {
public:
int fs(int n)
{
    int div=2,ans=0;
    while(n>1)
    {
        if(n%div==0)
        {
            ans+=div;
            n/=div;
        }
        else div++;
    }
    return ans;
}
    int smallestValue(int n) {
        while(1)
        {
            int sum=fs(n);
            if(n==sum) break;
            n=sum;
        }
        return n;
    }
};