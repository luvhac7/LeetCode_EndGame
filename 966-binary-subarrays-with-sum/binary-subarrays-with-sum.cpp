class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int t) {
        // int x=0;
        // for(int i=0;i<a.size();i++)
        // {
        //     int sum=0;
        //     for(int j=i;j<a.size();j++)
        //     {
        //         if(a[j]+sum==goal) x++;
        //     }
        // }
        // return x;
    map<int,int>f;
    f[0]=1;
    int ans=0,cs=0;
    for(int i:a)
    {
        cs+=i;
        int rem=cs-t;
        if(f.find(rem)!=f.end())
        {
            ans+=f[rem];
        }
        f[cs]++;
    }
    return ans;
    }
};