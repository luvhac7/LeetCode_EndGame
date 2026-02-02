class Solution {
public:
    int maxArea(vector<int>& a) {
        int l=0,h=a.size()-1,maxi=0;
        while(l<h)
        {
            maxi=max(maxi,min(a[l],a[h])*(h-l));
            if(a[l]<a[h])l++;
            else h--;
        }
        return maxi;
    }
};