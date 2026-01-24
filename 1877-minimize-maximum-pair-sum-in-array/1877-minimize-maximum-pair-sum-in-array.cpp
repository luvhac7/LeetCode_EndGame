class Solution {
public:
    int minPairSum(vector<int>& a) {
        sort(a.begin(),a.end());
        int l=0,r=a.size()-1,s=0;
        while(l<r)
        {
            int x=a[l]+a[r];
            if(x>s){
                s=x;
            }
            l++;r--;
        }
        return s;

    }
};