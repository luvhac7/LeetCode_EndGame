class Solution {
public:
int bs(vector<int>&a)
{
    int l=0,h=a.size()-1;
    while(l<h)
    {
        int m=l+(h-l)/2;
        if(a[m]<a[m+1])l=m+1;
        else h=m;
    }
    return l;
}
    int findPeakElement(vector<int>& a) {
        return bs(a);
    }
};