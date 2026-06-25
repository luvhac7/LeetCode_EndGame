class Solution {
public:
using vi=vector<int>;using vii=vector<vector<int>>;
using d=double;
static bool cmp(vi &a,vi &b)
{
    d p=1.0*a[0]/a[1];
    d q=1.0*b[0]/b[1];
    return p<q;
}
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        vii mp;int n=a.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                mp.push_back({a[j],a[i]});
            }
        }
        sort(mp.begin(),mp.end(),cmp);
        return mp[k-1];
    }
};