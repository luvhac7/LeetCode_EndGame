class Solution {
public:
int bs(vector<int>&a,int l,int h)
{
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(a[m]<=a[h]) h=m-1;
        //if(a[m]<a[h]) l=m+1;
        else{
            l=m+1;
        } 
    }
    return a[l];
}
    int findMin(vector<int>& a) {
        sort(a.begin(),a.end());
        int x=*min_element(a.begin(),a.end());
        return bs(a,0,a.size()-1);
       // return x;
    }
};