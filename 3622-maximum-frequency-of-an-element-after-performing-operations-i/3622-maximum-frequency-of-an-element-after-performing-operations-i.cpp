class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int no) {
        int mx=*max_element(nums.begin(),nums.end());
        int n=mx+k+2;
        vector<int>f(n,0);
        for(int x:nums) f[x]++;
        vector<int>pre(n,0);
        pre[0]=f[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+f[i];
        int ans=0;
        for(int x=0;x<n;x++)
        {
            if(f[x]==0 && no==0) continue;
            int l=max(0,x-k),r=min(n-1,x+k);
            int total=pre[r]-(l>0 ? pre[l-1]:0);
            int adj=total-f[x];
            int val=f[x]+min(no,adj);
            ans=max(ans,val);
        }
        return ans;
    }
};