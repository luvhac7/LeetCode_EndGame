class Solution {
public:
    int minPairSum(vector<int>&a) {
        sort(a.begin(),a.end());
        int s=0,l=0,r=a.size()-1;
        while(l<r)
        {
            if(a[l]+a[r]>s)
            {
                s=a[l]+a[r];
            }l++;r--;
        }
        return s;
    }
};