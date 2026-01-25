class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int n=a.size();
        int ans=a[k-1]-a[0];
        for(int i=0;i+k<=n;i++)
        {
            ans=min(ans,a[i+k-1]-a[i]);
        }
        return ans;
    }
};