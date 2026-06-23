class Solution {
public:
typedef vector<int> vi;
bool f(vi &a,int d,int mid)
{
    int need=1,cur=0;
    for(int i:a)
    {
        if(cur+i>mid)
        {
            need++;
            cur=i;
        }
        else{
            cur+=i;
        }
    }
    return d>=need;
}
    int shipWithinDays(vector<int>& a, int d) {
        //int n=w.size();
        int l=0,r=0;
        for(int i:a)
        {
            l=max(l,i);
            r+=i;
        }
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(f(a,d,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        // int x=n/2;
        // return w[x-1]+w[n-1];
        return ans;
    }
};