class Solution {
public:
    int maxProduct(vector<int>& a) {
        int x=INT_MIN,n=a.size();
     for(int i=0;i<n;i++)
     {
        for(int j=i+1;j<n;j++)
        {
            x=max(x,(a[i]-1)*(a[j]-1));
        }
     }   
     return x;
    }
};