class Solution {
public:
    int threeSumClosest(vector<int>& a, int tar) {
        sort(a.begin(),a.end());
        int n=a.size();
        int l=0,r=n-1;
        int ans=1e9+7;
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && a[i]==a[i-1]) continue;
            l=i+1;
            r=n-1;
            while(l<r)
            {
                int cs=a[i]+a[l]+a[r];
                if(cs==tar)
                {
                    return cs;
                }
                if(abs(tar-cs)<abs(tar-ans))
                {
                    ans=cs;
                }
                if(cs<tar) l+=1;
                else r-=1;
            }
        }
return ans;
    }
};