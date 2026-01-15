class Solution {
public:
bool solve(vector<int>&a,int mid,int k)
{
    int n=a.size();
    int l=0,h=n;
    while(l<h)
    {
        if(a[l]<=mid) k--,l+=2;
        else{
            l++;
        }
if(k==0) return true;
    }

    return k==0;
}
    int minCapability(vector<int>& a, int k) {
        int n=a.size();
        int l=0,h=1e9+1;

        while(l<h)
        {
            int mid=(l+h)/2;
            if(solve(a,mid,k))
            {
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};