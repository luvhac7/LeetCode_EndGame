class Solution {
public:
    int lengthOfLIS(vector<int>&a) {
        // int n=a.size(),l=1,ans=1;
        // for(int i=0;i<n-1;i++)
        // {
        //     if(a[i]<a[i+1]) l++;
        //     else{
        //         ans=max(ans,l);
        //         l=1;
        //     }
        // }
        // return l;
        if(a.empty()) return 0;
        int n=a.size();
        vector<int>ans;
        for(int i:a)
        {
            auto it=lower_bound(ans.begin(),ans.end(),i);
            if(it==ans.end()){
                ans.push_back(i);
            }
            else{
                *it=i;
            }
        }
        return ans.size();
    }
};