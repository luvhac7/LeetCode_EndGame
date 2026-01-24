class Solution {
public:
    int minPairSum(vector<int>& a) {
        int x=0,p=0,r=a.size()-1;
        sort(a.begin(),a.end());
        while(p<r)
        {
            int y=a[p]+a[r];
            if(y>x) x=y;
            p++;r--;
        }
        return x;
    }
};