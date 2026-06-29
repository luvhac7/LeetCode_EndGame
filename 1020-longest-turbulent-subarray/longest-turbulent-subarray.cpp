class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        int n=a.size();
        if(n<2)return a.size();
        int mx=1,ans=0;
        for(int i=1;i<n;i++)
        {
            int cur=(a[i-1]>a[i])-(a[i-1]<a[i]);
            if(cur==0){
                ans=i;
            }
            else if( i==1 || cur*((a[i-2]>a[i-1])-(a[i-2]<a[i-1]))!=-1){
                ans=i-1;
            }
            mx=max(mx,i-ans+1);
        }
        return mx;
    }
};