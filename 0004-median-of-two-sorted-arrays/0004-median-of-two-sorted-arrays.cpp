class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            ans.push_back(x);
        }for(int i=0;i<m;i++)
        {
            int x=b[i];
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        int total=ans.size();
        if(total%2==1)
        {
            return(double) ans[total/2];
        }else{
            return (ans[total/2-1]+ans[total/2])/2.0;
        }
    }
};