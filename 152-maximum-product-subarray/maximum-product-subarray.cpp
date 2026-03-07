class Solution {
public:
    int maxProduct(vector<int>& a) {
        int maxi=INT_MIN,p=1;
        for(int i=0;i<a.size();i++)
        {
            p*=a[i],maxi=max(p,maxi);if(p==0) p=1;
        }
        p=1;
        for(int i=a.size()-1;i>=0;i--)
        {
            p*=a[i],maxi=max(maxi,p);if(p==0)p=1;
        }
        return maxi;
    }
};