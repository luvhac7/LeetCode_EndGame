class Solution {
public:
    int subarraysDivByK(vector<int>&a, int k) {
        int n=a.size(),res=0,l=0;
    //  //   if(a[0]==-5) return 1; 
    //     for(int i=0;i<n;i++)
    //     {
    //         int sum=0;
    //         for(int j=i;j<n;j++)
    //         {
    //             sum+=a[j];
    //             if(sum%k==0) l++;
    //             else {
    //                 res=max(res,l);
    //             }
    //         }
    //     }
    //     return res;
    vector<int>cnt(k,0);
    cnt[0]=1;
    for(int i:a)
    {
        res+=i;
        int rem=((res%k)+k)%k;
        l+=cnt[rem];
        cnt[rem]++;
    }
    return l;
    }
};