class Solution {
public:
int f(int n)
{
    vector<int>a(n);a[0]=1;
    int i2,i3,i5,m2,m3,m5;
    i2=i3=i5=0;
    m2=2,m3=3,m5=5;
    for(int i=1;i<n;i++)
    {
        int cur=min(m2,min(m3,m5));
        cout<<cur<<" ";a[i]=cur;
        if(cur==m2) m2=a[++i2]*2;
        if(cur==m3) m3=a[++i3]*3;
        if(cur==m5) m5=a[++i5]*5;
    }
    cout<<"\n";
    return a[n-1];
}
    int nthUglyNumber(int n) {
        return f(n);
    }
};