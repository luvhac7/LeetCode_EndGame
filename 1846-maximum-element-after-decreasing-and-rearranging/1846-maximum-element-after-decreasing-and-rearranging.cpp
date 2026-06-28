class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        // reverse(a.begin(),a.end());
        // return *max_element(a.begin(),a.end());
        a[0]=1;
        for(int i=1;i<n;i++)
        {
            a[i]=min(a[i-1]+1,a[i]);
        }
        return a.back();
    }
};