class Solution {
public:
    int minPairSum(vector<int>&a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int l=0,r=n-1;
        int maxi=0;
        while(l<r)
        {
            int x=a[l]+a[r];
            if(x>maxi)
            {
                maxi=x;
            }
            l++;
            r--;
        }
        return maxi;
    }
};