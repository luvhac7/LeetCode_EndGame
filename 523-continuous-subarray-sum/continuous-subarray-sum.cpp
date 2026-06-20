class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
    //     int n=a.size();
    //    // if((k==1 || k==0) && n>=2) return true;
    //     if(n<2) return false;

    //     for(int i=0;i<n;i++)
    //     {
    //         int sum=a[i];
    //        // int x=0;
    //         //if(x%k==0) return true;
    //         for(int j=i+1;j<n;j++)
    //         {
    //             sum+=a[j];
    //             if(sum%k==0 ) return true;
    //         }
    //     }

    //     return false;
    //     // // return false;
    //     // int sum=0,n=a.size();
    //     // for(int i:a) sum+=i;
    //     // for(int i=n-1;i>=0;i--)
    //     // {
    //     //     int d=sum-a[i];
    //     //     cout<<d<<" ";
    //     //     if(sum<k && sum!=0) return false;
    //     //     if(d%k==0 && n>=2 ) return true;
    //     //     if(d<0){
    //     //         return false;
    //     //     }
    //     // }
    //     // return false;
    int n=a.size();
    if(n<2) return false;
    map<int,int>rem;
    rem[0]=-1;
    int sum=0,idx=0;
    for(int i:a)
    {
        sum+=i;
        int r=sum%k;
        if(r<0)r+=k;
        if(rem.count(r))
        {
            if(idx-rem[r]>=2)
            {
                return true;
            }
        }
        else{
            rem[r]=idx;
        }
        idx++;
    }
    return false;
    }
};