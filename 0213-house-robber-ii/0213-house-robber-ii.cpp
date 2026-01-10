class Solution {
public:
    int solve(vector<int>&a,int st,int end)
    {
        int p1=0,p2=0;
        for(int i=st;i<=end;i++)
        {
            int ans=max(p2+a[i],p1);
            p2=p1;
            p1=ans;
        }
        return p1;
    }
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        return max(solve(a,1,n-1),solve(a,0,n-2));
    }
};