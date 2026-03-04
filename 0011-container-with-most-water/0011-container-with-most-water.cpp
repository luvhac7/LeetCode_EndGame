class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0,r=h.size()-1;
        int maxi=0;
        while(l<r)
        {
            int mid=r-l;
            int cm=min(h[l],h[r]);
            maxi=max(maxi,mid*cm);
            if(h[l]<h[r]) l++;
            else r--;
        }
        return maxi;
    }
};