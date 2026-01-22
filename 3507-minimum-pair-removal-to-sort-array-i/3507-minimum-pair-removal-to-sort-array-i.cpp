class Solution {
public:
int cnt=0;
int solve(vector<int>&a)
{
    int mini=1e9;
    int x=-1;
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]+a[i+1]<mini)
        {
            mini=a[i]+a[i+1];
            x=i;
        }
    }
    return x;
}
void f(vector<int>&a,int x)
{
    a[x]+=a[x+1];
    a.erase(a.begin()+1+x);
}
    int minimumPairRemoval(vector<int>& a) {
        while(!is_sorted(a.begin(),a.end()))
        {
            f(a,solve(a));
            cnt++;
        }
        return cnt;
    }
};