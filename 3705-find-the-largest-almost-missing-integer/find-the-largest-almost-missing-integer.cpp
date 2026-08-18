class Solution {
public:
    int largestInteger(vector<int>& a, int k) {
        int n=a.size(),ans=-1;
        map<int,int>mp;
        if(n==k) return *max_element(a.begin(),a.end());
        else {
            for(int i=0;i<a.size();i++){
                mp[a[i]]++;
            }
            if(k==1){
                for(auto it:mp){
                    if(it.second==1){
                        ans=max(ans,it.first);
                    }
                }
                return ans;
            }
            int st=mp[a[0]],ls=mp[a[n-1]];
            if(st==1 && ls==1) return max(a[0],a[n-1]);
            else if (st==1) return a[0];
            else if(ls==1) return a[n-1];

        }
        return -1;
    }
};